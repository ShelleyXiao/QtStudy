#include <QCoreApplication>
#include <QTextStream>
#include <QtSerialPort/QSerialPortInfo>

QT_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream out(stdout);
    const auto serialPortInfos = QSerialPortInfo::availablePorts();

    out << QObject::tr("Total number of ports available: ")
        << serialPortInfos.count() << endl;

    const QString blankString = QObject::tr("N/A");

    QString description;
    QString manufactuer;
    QString serialNumber;

    for(const QSerialPortInfo &serialPortInfo : serialPortInfos) {
        description = serialPortInfo.description();
        manufactuer = serialPortInfo.manufacturer();
        serialNumber = serialPortInfo.serialNumber();

        out << endl
            << QObject::tr("Port: ") << serialPortInfo.portName() << endl
            << QObject::tr("Location : ") << serialPortInfo.systemLocation() << endl
            << QObject::tr("Description: ") << (!description.isEmpty() ? description : blankString) << endl
            << QObject::tr("Manufacturer: ") << (!manufactuer.isEmpty() ? manufactuer : blankString) << endl
            << QObject::tr("Serial Number: ") << (!serialNumber.isEmpty() ? serialNumber : blankString) << endl
            << QObject::tr("Vendor Identifier: ") << (serialPortInfo.hasVendorIdentifier()
                                                      ? QByteArray::number(serialPortInfo.vendorIdentifier()) : blankString) << endl
            << QObject::tr("Product Identifier: ") << (serialPortInfo.hasProductIdentifier()
                                                       ? QByteArray::number(serialPortInfo.productIdentifier()) : blankString) << endl
            << QObject::tr("Busy: ") << (serialPortInfo.isBusy() ? QObject::tr("Yes") : QObject::tr("No")) << endl;
    }

    return a.exec();
}
