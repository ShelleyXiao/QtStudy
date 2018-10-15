#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene sence;
    sence.setSceneRect(0, 0, 400, 400);

    QGraphicsView *view = new QGraphicsView(&sence);
    view->show();

    return a.exec();
}
