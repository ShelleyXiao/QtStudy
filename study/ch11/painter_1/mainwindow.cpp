#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.drawLine(QPointF(0, 0), QPointF(100, 100));

//    QPen pen;
//    pen.setColor(QColor(255,0,0));
//    QBrush brush(QColor(0,255, 0, 125));
//    painter.setPen(pen);;
//    painter.setBrush(brush);
//    painter.drawRect(50, 50, 200, 100);

    QPen pen(Qt::DotLine)        ;
    pen.setColor(Qt::black);
    QBrush brush(Qt::blue);
    brush.setStyle(Qt::HorPattern);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(50, 50, 200, 100);

    QRect rectangle(10.0, 20.0, 80.0, 60.0);
    int startAngle = 30 * 16;
    int endAngle = 120 * 16;

    painter.drawArc(rectangle, startAngle, endAngle);
}
