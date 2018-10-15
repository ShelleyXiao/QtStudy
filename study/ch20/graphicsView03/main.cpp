#include "mainwindow.h"
#include <QApplication>

#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    w.show();

    QGraphicsScene scene;
    scene.addText("hello world");

    scene.setForegroundBrush(QColor(255,255,255, 100));
    scene.setBackgroundBrush(Qt::green);

    QGraphicsView view(&scene);
    view.show();


    return a.exec();
}
