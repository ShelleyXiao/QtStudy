#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkReply>
#include <QFile>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void startRequest(QUrl url);

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;

    QNetworkReply *reply;
    QUrl url;
    QFile *file;

private slots:
//    void replyFinished(QNetworkReply *);
    void on_pushButton_clicked();
    void httpFinished();
    void httpReadyRead();
    void httpUpdateDataReadProgress(qint64, qint64);
};

#endif // MAINWINDOW_H
