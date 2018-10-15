#include "widget.h"
#include "ui_widget.h"

#include <QFileDialog>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    tcpClient = new QTcpSocket(this);
    totalBytes = 0;
    bytesWriten = 0;
    bytesToWrite = 0;
    loadSize = 4 * 1024;

    connect(tcpClient, SIGNAL(connected()), this, SLOT(startTransfer()));
    connect(tcpClient, SIGNAL(bytesWritten(qint64)), this, SLOT(updateClientProgress(qint64)));
    connect(tcpClient, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(QAbstractSocket::SocketError));

    ui->sendButton->setEnabled(false);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::openFile()
{
    fileName = QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty())
    {
        ui->sendButton->setEnabled(true);
        ui->clientStatusLable->setText(tr("打开文件 %1 成功").arg(fileName));
    }
}

void Widget::send()
{
    ui->sendButton->setEnabled(false);
    bytesWriten = 0;
    ui->clientStatusLable->setText(tr("连接..."));
    tcpClient->connectToHost(ui->hostLineEdit->text(), ui->portLineEdit->text().toInt());
}

void Widget::startTransfer()
{
    localFile = new QFile(fileName);
    if(!localFile->open(QFile::ReadOnly))
    {
        qDebug() << "open file faild";
        return;
    }
    totalBytes = localFile->size();
    QDataStream sendOut(&outBlock, QIODevice::WriteOnly);
    sendOut.setVersion(QDataStream::Qt_5_8);
    QString currentFileName = fileName.right(fileName.size() - fileName.lastIndexOf("/") - 1);
    sendOut << qint64(0) << qint64(0) << currentFileName;
    totalBytes += outBlock.size();
    sendOut.device()->seek(0);
    sendOut << totalBytes << qint64(outBlock.size() - sizeof(qint64) * 2);
    bytesToWrite = totalBytes - tcpClient->write(outBlock)   ;

    ui->clientStatusLable->setText(tr("已连接"));
    outBlock.resize(0);
}

void Widget::updateClientProgress(qint64 numBytes)
{
    bytesWriten += numBytes;
    if(bytesWriten > 0)
    {
        outBlock = localFile->read(qMin(bytesToWrite, loadSize));
        bytesToWrite -= (int)tcpClient->write(outBlock);
        outBlock.resize(0);
    }
    else
    {
        localFile->close();
    }
    ui->clientProgressBar->setMaximum(totalBytes);
    ui->clientProgressBar->setValue(bytesWriten);
    if(bytesWriten == totalBytes)
    {
        ui->clientStatusLable->setText(tr("传送文件%1成功").arg(fileName));
        localFile->close();
        tcpClient->close();
    }
}

void Widget::displayError(QTcpSocket::SocketError)
{
    qDebug() << tcpClient->errorString();
    tcpClient->close();
    ui->clientStatusLable->setText(tr("客户端就绪"));
    ui->clientProgressBar->reset();
    ui->sendButton->setEnabled(true);
}

void Widget::on_openButton_clicked()
{
    openFile();
}

void Widget::on_sendButton_clicked()
{
    send();
}
