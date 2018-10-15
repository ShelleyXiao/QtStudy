#include "widget.h"
#include "ui_widget.h"

#include <QHostAddress>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    totalBytes = 0;
    bytesReceived = 0;
    fileNameSize = 0;

    connect(&tcpServer, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_startButton_clicked()
{
    start();
}

void Widget::start()
{
    ui->startButton->setEnabled(false);
    if(!tcpServer.listen(QHostAddress::LocalHost, 6666))
    {
        qDebug() << tcpServer.errorString();
        close();
        return;
    }

    ui->serverStatusLabel->setText(tr("监听"));
}

void Widget::acceptConnection()
{
    tcpServerConnection = tcpServer.nextPendingConnection();
    connect(tcpServerConnection, SIGNAL(readyRead()), this, SLOT(updateServerProgress()));
    connect(tcpServerConnection, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));
    ui->serverStatusLabel->setText(tr("接受连接"));
    tcpServer.close();
}

void Widget::updateServerProgress()
{
    QDataStream in(tcpServerConnection);
    in.setVersion(QDataStream::Qt_5_8);
    if(bytesReceived <= sizeof(qint64) * 2)
    {
        if((tcpServerConnection->bytesAvailable() >= sizeof(qint64) * 2)
                && (fileNameSize == 0))
        {
            in >> totalBytes >> fileNameSize;
            bytesReceived += sizeof(qint64) * 2;
        }
        if((tcpServerConnection->bytesAvailable() >= fileNameSize)
                && (fileNameSize != 0))
        {
            in >> fileName;
            ui->serverStatusLabel->setText(tr("接受文件中 %1..").arg(fileName));
            bytesReceived += fileNameSize;
            localFile = new QFile(fileName);
            if(!localFile->open(QFile::WriteOnly))
            {
                qDebug() << "open file error";
                return;
            }
        } else return;
    }

    if(bytesReceived < totalBytes)
    {
        bytesReceived += tcpServerConnection->bytesAvailable();
        inBlock = tcpServerConnection->readAll();
        localFile->write(inBlock);
        inBlock.resize(0);
    }

    ui->serverProgressBar->setMaximum(totalBytes);
    ui->serverProgressBar->setValue(bytesReceived);

    if(bytesReceived == totalBytes)
    {
        tcpServerConnection->close();;
        localFile->close();
        ui->startButton->setEnabled(true);
        ui->serverStatusLabel->setText(tr("介绍%1文件成功").arg(fileName));
    }

}

void Widget::displayError(QAbstractSocket::SocketError socketError)
{
    qDebug() << tcpServerConnection->errorString();
    tcpServerConnection->close();
    ui->serverStatusLabel->setText(tr("服务端就绪"));
    ui->serverProgressBar->reset();
    ui->startButton->setEnabled(true);
}
