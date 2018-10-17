#include "diagramitem.h"

#include <QPainter>
#include <QGraphicsScene>
#include <QMenu>
#include <QGraphicsSceneContextMenuEvent>

#include "arrow.h"

DiagramItem::DiagramItem(DiagramItem::DiagramType type, QMenu *contextMenu, QGraphicsItem *parent)
    :QGraphicsPolygonItem(parent)
{
    myDiagramType = type;
    this->contextMenu = contextMenu;

    QPainterPath path;
    switch (myDiagramType) {
    case StartEnd:
        path.moveTo(200, 50);
        path.arcTo(150, 0, 50, 50, 0, 90);
        path.arcTo(50, 0, 50, 50, 90, 90);
        path.arcTo(50, 50, 50, 50, 180, 90);
        path.arcTo(150, 50, 50, 50, 270, 90);
        path.lineTo(200, 25);
        myPolygon = path.toFillPolygon();
        break;
    case Conditional:
        myPolygon << QPointF(-100, 0) << QPointF(0, 100)
                  << QPointF(100, 0) << QPointF(0, -100)
                  << QPointF(-100, 0);

        break;
    case Step:
        myPolygon << QPointF(-100, -100) << QPointF(100, -100)
                  << QPointF(100, 100) << QPointF(-100, 100)
                  << QPointF(-100, -100);
        break;
    case Io:
        myPolygon << QPointF(-120, -80) << QPointF(-70, 80)
                  << QPointF(120, 80) << QPointF(70, -80)
                  << QPointF(-120, -80);
        break;
    default:
        myPolygon << QPointF(-120, -80) << QPointF(-70, 80)
                  << QPointF(120, 80) << QPointF(70, -80)
                  << QPointF(-120, -80);
        break;
    }
    setPolygon(myPolygon);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}

void DiagramItem::removeArrow(Arrow *arrow)
{
    int index = arrows.indexOf(arrow);
    if(index != -1) {
        arrows.removeAt(index);;
    }
}

void DiagramItem::remvowArrows()
{
    foreach(Arrow *a , arrows) {
        a->startItem()->removeArrow(a);
        a->endItem()->removeArrow(a);
        scene()->removeItem(a);
        delete a;
    }

}

void DiagramItem::addArrow(Arrow *a)
{
    arrows.append(a);
}

QPixmap DiagramItem::image() const
{
    QPixmap pixmap(250, 250);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setPen(QPen(Qt::black, 8));
    painter.translate(125, 125);
    painter.drawPolygon(myPolygon);

    return pixmap;
}

void DiagramItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    scene()->clearSelection();
    setSelected(true);
    contextMenu->exec(event->screenPos());
}

QVariant DiagramItem::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
     if(change == QGraphicsItem::ItemPositionChange) {
         foreach (Arrow *a, arrows) {
            a->updatePosition();
         }
     }
     return value;
}
