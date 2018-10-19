#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
#include <QTime>
#include "myview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    MyView w;
    w.show();

    return a.exec();
}
