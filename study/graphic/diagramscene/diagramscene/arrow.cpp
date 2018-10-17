#include "arrow.h"
#include <math.h>
#include <QPen>
#include <QPainter>
#include <QLineF>
#include "diagramitem.h"



Arrow::Arrow(DiagramItem *statItem, DiagramItem *endItem, QGraphicsItem *parent)
    :QGraphicsLineItem(parent)
{
    mStartItem = statItem;
    mEndItem = endItem;
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    mColor = Qt::black;
    setPen(QPen(mColor, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
}

QRectF Arrow::boundingRect() const
{
    qreal extra = (pen().width() + 20) / 2;
    return QRectF(line().p1(), QSizeF(line().p2().x() - line().p1().x(),
                                      line().p2().y() - line().p2().y()))
            .normalized()
            .adjusted(-extra, -extra, extra, extra);

}

QPainterPath Arrow::shape() const
{
    QPainterPath path = QGraphicsLineItem::shape();
    path.addPolygon(arrowHead);
    return path;
}

void Arrow::updatePosition()
{
    QLineF lined(mapFromItem(mStartItem, 0, 0), mapFromItem(mEndItem, 0, 0));
    setLine(lined);
}

void Arrow::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (mStartItem->collidesWithItem(mEndItem))
            return;

        QPen myPen = pen();
        myPen.setColor(mColor);
        qreal arrowSize = 20;
        painter->setPen(myPen);
        painter->setBrush(mColor);
    //! [4] //! [5]

        QLineF centerLine(mStartItem->pos(), mEndItem->pos());
        QPolygonF endPolygon = mEndItem->polygon();
        QPointF p1 = endPolygon.first() + mEndItem->pos();
        QPointF p2;
        QPointF intersectPoint;
        QLineF polyLine;
        for (int i = 1; i < endPolygon.count(); ++i) {
            p2 = endPolygon.at(i) + mEndItem->pos();
            polyLine = QLineF(p1, p2);
            QLineF::IntersectType intersectType =
                polyLine.intersect(centerLine, &intersectPoint);
            if (intersectType == QLineF::BoundedIntersection)
                break;
            p1 = p2;
        }

        setLine(QLineF(intersectPoint, mStartItem->pos()));
    //! [5] //! [6]

        double angle = ::acos(line().dx() / line().length());
        if (line().dy() >= 0)
            angle = (M_PI * 2) - angle;

        QPointF arrowP1 = line().p1() + QPointF(sin(angle + M_PI / 3) * arrowSize,
                                        cos(angle + M_PI / 3) * arrowSize);
        QPointF arrowP2 = line().p1() + QPointF(sin(angle + M_PI - M_PI / 3) * arrowSize,
                                        cos(angle + M_PI - M_PI / 3) * arrowSize);

        arrowHead.clear();
        arrowHead << line().p1() << arrowP1 << arrowP2;
    //! [6] //! [7]
        painter->drawLine(line());
        painter->drawPolygon(arrowHead);
        if (isSelected()) {
            painter->setPen(QPen(mColor, 1, Qt::DashLine));
            QLineF myLine = line();
            myLine.translate(0, 4.0);
            painter->drawLine(myLine);
            myLine.translate(0,-8.0);
            painter->drawLine(myLine);
        }
}
