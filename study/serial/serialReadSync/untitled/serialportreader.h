#ifndef SERIALPORTREADER_H
#define SERIALPORTREADER_H

#include <QtSerialPort/QSerialPort>

#include <QTextStream>
#include <QTimer>
#include <QByteArray>
#include <QObject>

class SerialportReader : public QObject
{
    Q_OBJECT

public:
    explicit  SerialportReader(QSerialPort *serialPort, QObject *parent = 0);
    ~SerialportReader();

private slots:
    void handleReadyRead();
    void handleTimeout();
    void handleError(QSerialPort::SerialPortError error);

private:
    QSerialPort *m_serialPort;
    QByteArray m_readData;
    QTextStream m_standardOutput;
    QTimer m_timer;

};

#endif // SERIALPORTREADER_H
