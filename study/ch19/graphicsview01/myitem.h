#ifndef MYITEM_H
#define MYITEM_H

#include <QtGui>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

class MyItem : public QGraphicsItem {

public:
    MyItem();
    virtual ~MyItem();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    QColor color;

};

class RectItem : public QGraphicsItem {
public:
    RectItem();
    ~RectItem();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event);
    void dropEvent(QGraphicsSceneDragDropEvent *event);

    void keyPressEvent(QKeyEvent *evnet);

private:
    QColor color;
    bool dragOver;
};


#endif // MYITEM_H


