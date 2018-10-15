#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    recevier = new QUdpSocket(this);
    recevier->bind(45454, QUdpSocket::ShareAddress);
    connect(recevier, SIGNAL(readyRead()),this, SLOT(processDatagram()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::processDatagram()
{
    while(recevier->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(recevier->pendingDatagramSize());
        recevier->readDatagram(datagram.data(), datagram.size());
        ui->label->setText(datagram);
    }
}
