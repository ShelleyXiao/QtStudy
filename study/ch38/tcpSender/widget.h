#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtNetwork>
#include <QFile>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QTcpSocket* tcpClient;

    qint64 totalBytes;
    qint64 bytesWriten;
    qint64 bytesToWrite;
    qint64 loadSize;
    QString fileName;
    QByteArray outBlock;

    QFile* localFile;

    void openFile();

private slots:
    void send();
    void startTransfer();
    void updateClientProgress(qint64);
    void displayError(QTcpSocket::SocketError);
    void on_openButton_clicked();
    void on_sendButton_clicked();
};

#endif // WIDGET_H
