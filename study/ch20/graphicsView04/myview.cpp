#include "myview.h"

#include <QWheelEvent>
#include <QGraphicsRectItem>
#include <QGraphicsItemGroup>
#include <QDebug>

//MyView::MyView()
//{

//}

MyView::MyView(QWidget *parent):QGraphicsView(parent)
{
    resize(800, 600);
    setAlignment(Qt::AlignLeft | Qt::AlignTop);
    setBackgroundBrush(QPixmap("E:\\private_workspace\\qt_workspace\\study\\ch20\\test.jpg"));
    QGraphicsScene *sence = new QGraphicsScene(this);

    QGraphicsRectItem *item1 = new QGraphicsRectItem(0,0,20,20);
    item1->setBrush(Qt::red);
    item1->setPos(10, 40);
    //    sence->addItem(item1);

    QGraphicsRectItem *item2 = new QGraphicsRectItem(0,0,20,20);
    item2->setBrush(Qt::gray);
    item2->setPos(20, 0);
    //    sence->addItem(item2);

    QGraphicsRectItem *item3 = new QGraphicsRectItem(0,0,20,20);
    item3->setBrush(Qt::black);
    item3->setPos(30, 0);
    //    sence->addItem(item3);

    QGraphicsRectItem *item4 = new QGraphicsRectItem(0,0,20,20);
    item4->setBrush(Qt::green);
    item4->setPos(30, 50);
    //    sence->addItem(item4);

    QGraphicsItemGroup *group = new QGraphicsItemGroup();
    group->addToGroup(item1);
    group->addToGroup(item2);
    group->addToGroup(item3);
    group->addToGroup(item4);

    sence->addItem(group);

    setScene(sence);

    qDebug() << "item at(20, 0)" << itemAt(20, 0);
    qDebug() << "item at(30, 0)" << itemAt(30, 0);

    //    setDragMode(QGraphicsView::ScrollHandDrag);
    sence->setSceneRect(0,0,1000, 800);
}

MyView::~MyView()
{

}

void MyView::wheelEvent(QWheelEvent *event)
{
    if(event->delta() > 0) {
        scale(0.5, 0.5);
    }
    else {
        scale(2, 2);
    }
}

void MyView::mousePressEvent(QMouseEvent *event)
{
    //    rotate(90);
}

void MyView::keyPressEvent(QKeyEvent *event)
{
    qDebug() << items();
    items().at(0)->setPos(100, 0);
    items().at(1)->setPos(0, 100);

    QGraphicsView::keyPressEvent(event);
}

