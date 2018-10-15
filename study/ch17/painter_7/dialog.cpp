#include "dialog.h"
#include "ui_dialog.h"

#include <QPainter>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    resize(500, 500);
    pix = QPixmap(200, 200);
    pix.fill(Qt::white);

    scale = 1.0f;
    button = new QPushButton(this);
    button->setText(tr("zoom in"));
    button->move(500, 450);
    connect(button, SIGNAL(clicked()), this, SLOT(zoomIn()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *event)
{

    if(scale != 1) {
        QPixmap copyPix(pix.size() * scale);
        QPainter pter(&copyPix);
        pter.scale(scale, scale);
        pter.drawPixmap(0, 0, pix);;
        pix = copyPix;
        scale = 1;
    }
    QPainter pp(&pix);
    pp.scale(scale, scale);
    pp.drawLine(lastPoint/scale, endPoint/scale);
    lastPoint = endPoint;
    QPainter painters(this);
    painters.drawPixmap(0, 0, pix);
}

void Dialog::mouseMoveEvent(QMouseEvent *event)
{
    if(event->button() & Qt::LeftButton) {
        endPoint = event->pos();
        update();
    }
}

void Dialog::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) {
        lastPoint = event->pos();
    }
}

void Dialog::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) {
        endPoint = event->pos();
        update();
    }
}

void Dialog::zoomIn()
{
    scale *= 2;
    update();
}
