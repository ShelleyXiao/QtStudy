#include <QtGui>

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

#include "myitem.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

    QGraphicsScene *sence = new QGraphicsScene();
    for(int i = 0; i < 5; i++) {
        MyItem *item = new MyItem();
        item->setPos(i * 50 + 20, 100);
        sence->addItem(item);
    }
    RectItem *rectItem = new RectItem();
    rectItem->setPos(100, 200);
    sence->addItem(rectItem);
    QGraphicsView *view = new QGraphicsView();
    view->setScene(sence);
    view->resize(400, 300);
    view->show();


    return a.exec();
}
