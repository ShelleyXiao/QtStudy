#include "dialog.h"
#include "ui_dialog.h"

#include <QPainter>

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

void Dialog::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("E:\\private_workspace\\qt_workspace\\study\\ch15\\text_italic.png");
    Q_ASSERT(!pix.isNull());
    painter.drawPixmap(0, 0, 60, 60, pix);

    painter.translate(100, 100);
    painter.drawPixmap(0, 0, 60, 60, pix);

    painter.translate(63, 33);
    painter.rotate(90);
    painter.translate(-63, -33);
    painter.drawPixmap(0, 0, 60, 60, pix);
}
