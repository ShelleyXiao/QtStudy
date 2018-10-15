#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QNetworkRequest>
#include <QTextCodec>
#include <QFileInfo>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    manager = new QNetworkAccessManager(this);
    //    connect(manager, SIGNAL(finished(QNetworkReply *)),
    //            this, SLOT(replyFinished(QNetworkReply *)));
    //    manager->get(QNetworkRequest(QUrl("http://www.qter.org")));
    ui->progressBar->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete manager;

}

void MainWindow::startRequest(QUrl url)
{
    reply = manager->get(QNetworkRequest(url));
    connect(reply, SIGNAL(readyRead()), this, SLOT(httpReadyRead()));
    connect(reply, SIGNAL(finished()), this, SLOT(httpFinished()));
    connect(reply, SIGNAL(downloadProgress(qint64,qint64)),
            this, SLOT(httpUpdateDataReadProgress(qint64,qint64)));

}

//void MainWindow::replyFinished(QNetworkReply *reply)
//{
//    QTextCodec *codec = QTextCodec::codecForName("utf8");
//    QString all = codec->toUnicode(reply->readAll());
//    ui->textBrowser->setText(all);
//    reply->deleteLater();
//}

void MainWindow::on_pushButton_clicked()
{
    url = ui->lineEdit->text();
    QFileInfo info(url.path());
    QString fileName(info.fileName());
    if(fileName.isEmpty()) fileName = "index.html";
    file = new QFile(fileName);
    if(!file->open(QIODevice::WriteOnly))
    {
        qDebug() << "file not open";
        delete file;
        file = 0;
        return;
    }

    startRequest(url);
    ui->progressBar->setValue(0);
    ui->progressBar->show();
}

void MainWindow::httpFinished()
{
//    ui->progressBar->hide();
    file->flush();
    file->close();
    reply->deleteLater();
    reply = 0;
    delete file;
    file = 0;
}

void MainWindow::httpReadyRead()
{
    if(file) file->write(reply->readAll());
}

void MainWindow::httpUpdateDataReadProgress(qint64 bytesRead, qint64 totalBytes)
{
    ui->progressBar->setMaximum(totalBytes);
    ui->progressBar->setValue(bytesRead);
}
