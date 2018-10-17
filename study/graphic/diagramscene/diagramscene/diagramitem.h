#ifndef DIAGRAMITEM_H
#define DIAGRAMITEM_H

#include <QGraphicsPixmapItem>
#include <QList>

QT_BEGIN_NAMESPACE

class QPixmap;
class QGraphicsItem;
class QGraphicsScene;
class QGraphicsSceneContextMenuEvent;
class QGraphicsSceneMouseEvent;
class QTextEdit;
class QMenu;
class QPainter;
class QStyleOptionGraphicsItem;
class QWidget;
class QPolygonF;

QT_END_NAMESPACE

class Arrow;

class DiagramItem : public QGraphicsPolygonItem {

public:
    enum {Type = UserType + 15};
    enum DiagramType {
        Step, Conditional, StartEnd, Io
    };

    DiagramItem(DiagramType type, QMenu *contextMenu, QGraphicsItem *parent = 0);

    void removeArrow(Arrow *arrow);
    void remvowArrows();
    DiagramType diagramType() const { return myDiagramType;}
    QPolygonF polygon() const {
        return myPolygon;
    }

    void addArrow(Arrow *a);
    QPixmap image() const;
    int type() const override {
        return Type;
    }


protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

private:
    DiagramType myDiagramType;
    QPolygonF myPolygon;
    QMenu *contextMenu;
    QList<Arrow *>arrows;


};


#endif // DIAGRAMITEM_H
