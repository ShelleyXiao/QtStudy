#include "dialog.h"
#include "ui_dialog.h"

#include <QPainter>
#include <QDebug>
#include <QPixmap>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *e)
{
//    QPainter painter(this);
//    painter.setBrush(Qt::red);
//    painter.drawRect(0, 0, 100, 100);
//    painter.setBrush(Qt::yellow);
//    painter.drawRect(-50, -50, 100, 100);

//    //平移变换
//    QPainter painter(this);
//    painter.setBrush(Qt::red);
//    painter.drawRect(0, 0, 50, 50);;
//    painter.translate(100, 100);
//    painter.setBrush(Qt::yellow);
//    painter.drawRect(0, 0, 50, 50);
//    painter.translate(-100, -100);
//    painter.drawLine(QPointF(0, 0), QPointF(30, 30));


//    //缩放
//    QPainter painter(this);
//    painter.setBrush(Qt::red);
//    painter.drawRect(0, 0, 100, 100);
//    painter.scale(2, 2);
//    painter.setBrush(Qt::yellow);
//    painter.drawRect(50, 50, 50, 50);

//    //扭曲
//    QPainter painter(this);
//    painter.setBrush(Qt::red);
//    painter.drawRect(0, 0, 50, 50);
//    painter.shear(0, 1);
//    painter.setBrush(Qt::yellow);
//    painter.drawRect(50, 0, 50, 50);


      //旋转
//      QPainter painter(this);
//      painter.setBrush(Qt::red);
//      painter.drawLine(0,0 , 100, 0);
//      painter.rotate(30);
//      painter.drawLine(0, 0, 100, 0);
//      painter.translate(100, 100);
//      painter.rotate(30);// 这里实际旋转60度
//      painter.drawLine(0, 0, 100, 0);

//      QPainter painter(this);
//      painter.setBrush(Qt::red);
//      painter.drawLine(0,0 , 100, 0);
//      painter.rotate(30);
//      painter.drawLine(0, 0, 100, 0);
//      painter.rotate(-30);
//      painter.translate(100, 100);
//      painter.rotate(30);// 这里实际旋转30度
//      painter.drawLine(0, 0, 100, 0);

//    QPainter painter(this);
//    painter.save();
//    painter.translate(100, 100);
//    painter.setPen(Qt::red);
//    painter.drawLine(0, 0, 50, 50);
//    painter.restore();
////    painter.setPen(Qt::yellow);
//    painter.drawLine(0, 0, 50, 50);

//      QPainter painter(this);
////      painter.drawRect(0, 0, 50, 50);
////      painter.scale(1, 2);
////      painter.drawRect(50, 50, 50, 50);
//    painter.drawLine(0, 0, 100, 0);
//    painter.rotate(30);
//    painter.setPen(Qt::red);
//    painter.drawLine(0, 0, 100, 0);

    //绘图设备坐标
//    QPainter painter(this);
//    QPixmap pix(200, 200);
//    qDebug() << pix.size();
//    pix.fill(Qt::red);
////    painter.drawPixmap(100, 100, pix);

//    QPainter pp(&pix);
//    pp.drawLine(0, 0, 50, 50);
//    pp.scale(2,2);
//    pp.drawLine(0, 0, 50, 50);
//    qDebug() << pix.size();

//    painter.drawPixmap(0, 0, pix);

    QPainter painter(this);
    QPixmap pix(200, 200);
    qDebug() << pix.size();
    painter.scale(2,2);
    pix.fill(Qt::red);
//    painter.drawPixmap(100, 100, pix);
    QPainter pp(&pix);
    pp.drawLine(0, 0, 50, 50);
    qDebug() << pix.size();

    painter.drawPixmap(0, 0, pix);
}

void Dialog::mouseMoveEvent(QMouseEvent *e)
{
    qDebug() << e->pos();
}
