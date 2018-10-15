#include "widget.h"
#include <QApplication>

#include "myview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //    Widget w;
    //    w.show();

    MyView view;
    view.show();

    return a.exec();
}
