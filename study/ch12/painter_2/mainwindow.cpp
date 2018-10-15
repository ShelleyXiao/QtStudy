#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QLinearGradient>


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
    QLinearGradient linerGradient(QPointF(40,190), QPointF(70, 190));
    linerGradient.setColorAt(0, Qt::yellow);
    linerGradient.setColorAt(0.5, Qt::red);
    linerGradient.setColorAt(1, Qt::green);
    linerGradient.setSpread(QGradient::RepeatSpread);
    linerGradient.setSpread(QGradient::PadSpread);
    linerGradient.setSpread(QGradient::ReflectSpread);
    painter.setBrush(linerGradient);

    painter.drawRect(10, 20, 90, 40);

    QRadialGradient radialGradient(QPointF(100, 190) , 50, QPointF(275, 200));
    radialGradient.setColorAt(0, QColor(255, 255, 100, 150));
    radialGradient.setColorAt(1, QColor(0, 0, 0, 50));
    painter.setBrush(radialGradient);

    painter.drawEllipse(QPointF(100, 190), 50, 50);

    QConicalGradient conicalGradient(QPointF(250, 190), 60);
    conicalGradient.setColorAt(0.2, Qt::cyan);
    conicalGradient.setColorAt(0.9, Qt::black);
    painter.setBrush(conicalGradient);
    painter.drawEllipse(QPointF(200, 190), 50, 50);
}
