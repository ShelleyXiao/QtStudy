#include "serialportreader.h"

#include <QCoreApplication>

QT_USE_NAMESPACE

SerialportReader::SerialportReader(QSerialPort *serialPort, QObject *parent)
    :QObject(parent),
      m_serialPort(serialPort),
      m_standardOutput(stdout)
{
    connect(m_serialPort, &QSerialPort::readyRead, this, &SerialportReader::handleReadyRead);
    connect(m_serialPort, static_cast<void (QSerialPort:: *)(QSerialPort::SerialPortError)>(&QSerialPort::error),
            this, &SerialportReader::handleError);
    connect(&m_timer, &QTimer::timeout, this, &SerialportReader::handleTimeout);

    m_timer.start(5000);
}

SerialportReader::~SerialportReader()
{

}

void SerialportReader::handleReadyRead()
{
    m_readData.append(m_serialPort->readAll());
    if(!m_timer.isActive()) {
        m_timer.start(5000);
    }
}

void SerialportReader::handleTimeout()
{
    if(m_readData.isEmpty()) {
        m_standardOutput << QObject::tr("No data was current avilable for reading from port %1")
                            .arg(m_serialPort->portName()) << endl;
    } else {
        m_standardOutput << QObject::tr("Data successfully received from port %1")
                            .arg(m_serialPort->portName()) << endl;
        m_standardOutput << QObject::tr("received data: ") << m_readData << endl;
    }

    QCoreApplication::quit();
}

void SerialportReader::handleError(QSerialPort::SerialPortError error)
{
    if(error == QSerialPort::ReadError) {
        m_standardOutput << QObject::tr("An I/O error occurred while reading the data from port %1, error: %2").arg(m_serialPort->portName()).arg(m_serialPort->errorString()) << endl;
        QCoreApplication::exit(1);
    }
}
