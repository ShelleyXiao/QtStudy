﻿#include "widget.h"
#include <QApplication>

#include "analogclock.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AnalogClock w;
    w.show();

    return a.exec();
}
