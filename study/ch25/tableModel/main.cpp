#include "mainwindow.h"
#include <QApplication>

#include <QTextCodec>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());

    if(!createConnection()) {
        return 1;
    }

    MainWindow w;
    w.show();

    return a.exec();
}
