#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
//    ui->setupUi(this);
//    QString localHostname = QHostInfo::localHostName();
//    qDebug() << "localhost name: " << localHostname;

//    QHostInfo info = QHostInfo::fromName(localHostname);
//    qDebug() << "IP address: " << info.addresses();

//    for(QHostAddress address : info.addresses())
//    {

//        if(address.protocol() == QAbstractSocket::IPv4Protocol)
//        {
//            qDebug() << address.toString();
//        }
//    }

//    QHostInfo::lookupHost("www.qter.org", this, SLOT(lookup(const QHostInfo)));

    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
    foreach (QNetworkInterface interface, list) {
        qDebug() << "Device: " << interface.name();
        qDebug() << "HardwareAddress: " << interface.hardwareAddress();

        QList<QNetworkAddressEntry> entryList = interface.addressEntries();
        foreach (QNetworkAddressEntry entry, entryList) {
            qDebug() << "Ip address: " << entry.ip().toString();
            qDebug() << "network mask address: " << entry.netmask().toString();
            qDebug() << "broadcast address: " << entry.broadcast().toString();
        }
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::lookup(const QHostInfo &host)
{
    qDebug() << host.addresses().first().toString();
}
