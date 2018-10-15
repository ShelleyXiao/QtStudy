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
    QPainter painter(this);
//    painter.drawText(100, 100, "wwww");
    QRectF rect(20, 20, 300, 300);
    painter.drawRect(rect);
    QPen pen(Qt::red);
    painter.setPen(pen);
    painter.drawText(rect, Qt::AlignJustify, tr("ssssdfdf"));

    QFont font("宋体", 15, QFont::Bold, true);
    font.setUnderline(true);
    font.setOverline(true);
    font.setCapitalization(QFont::SmallCaps);
    font.setLetterSpacing(QFont::AbsoluteSpacing, 10);

    painter.setFont(font);
    painter.setPen(Qt::green);
    painter.drawText(120, 80, tr("dddddddddddddddddddd"));
    painter.translate(50, 50);
    painter.rotate(90);
    painter.drawText(0, 0, "wwwwwwwwwwwwwwww");

}
