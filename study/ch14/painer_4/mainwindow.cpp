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

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainterPath path;
    path.addEllipse(100, 100, 50, 50);
    path.lineTo(200, 200);;
    QPainter painter(this);
    painter.setPen(Qt::red);
    painter.setBrush(Qt::blue);
    painter.drawPath(path);

    QPainterPath path2;
    path2.addPath(path);
    path2.translate(100, 0);
    painter.drawPath(path2);
}
