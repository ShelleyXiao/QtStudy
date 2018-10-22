#include <QCoreApplication>

#include "serialportreader.h"

#include <QTextStream>
#include <QCoreApplication>
#include <QFile>
#include <QStringList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int argumenCount = QCoreApplication::arguments().size();
    QStringList argumentList = QCoreApplication::arguments();

    QTextStream out(stdout);

    if(argumenCount == 1) {
        out << QObject::tr("Usage: %1 <serialportname> [baudrate]").arg(argumentList.first()) << endl;
        return 1;
    }

    QSerialPort serialport;
    QString serialPortName = argumentList.at(1);
    serialport.setPortName(serialPortName);

    int serialPortBaudRate = (argumenCount > 2) ? argumentList.at(2).toInt() : QSerialPort::Baud115200;
    serialport.setBaudRate(serialPortBaudRate);

    if(!serialport.open(QIODevice::ReadOnly)) {
        out << QObject::tr("Failed to open port %1, error: %2").arg(serialPortName).arg(serialport.errorString()) << endl;
               return 1;
    }

    SerialportReader serialportReader(&serialport);

    return a.exec();
}
