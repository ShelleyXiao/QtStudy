#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore/QtGlobal>
#include <QtSerialPort/QSerialPort>

class QLabel;


namespace Ui {
class MainWindow;
}

class Console;
class SettingsDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void openSerialPort();
    void closeSerialPort();
    void about();
    void writeData(const QByteArray &data);
    void readData();

    void handleError(QSerialPort::SerialPortError error);

private:
     void initActionsConnections();

private:
    Ui::MainWindow *ui;

    void showStatusMessage(const QString &msg);

    QLabel *status;
    Console *console;
    SettingsDialog *settings;
    QSerialPort *serial;


};

#endif // MAINWINDOW_H
