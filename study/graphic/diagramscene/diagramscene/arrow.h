#ifndef ARROW_H
#define ARROW_H

#include <QGraphicsLineItem>

QT_BEGIN_NAMESPACE

class QGraphicsPolygonItem;
class QGraphicsItem;
class QGraphicsScene;
class QGraphicsSceneMouseEvent;
class QRectF;
class QPainterPath;

QT_END_NAMESPACE

class DiagramItem;

class Arrow : public QGraphicsLineItem {

public:
    enum {Type = UserType + 4};
    Arrow(DiagramItem *statItem, DiagramItem *endItem,
          QGraphicsItem *parent = 0);

    int type() const override {return Type;}
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void setColor(const QColor &color) {
        mColor  = color;
    }
    DiagramItem *startItem() const {
        return mStartItem;
    }
    DiagramItem *endItem() const {
        return mEndItem;
    }

    void updatePosition();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = Q_NULLPTR) Q_DECL_OVERRIDE;

private:
    DiagramItem *mStartItem;
    DiagramItem *mEndItem;
    QColor mColor;
    QPolygonF arrowHead;


};

#endif // ARROW_H
