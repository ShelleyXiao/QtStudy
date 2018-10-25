#include "settingsdialog.h"
#include "ui_settingsdialog.h"

#include <QtSerialPort/QSerialPortInfo>
#include <QIntValidator>
#include <QLineEdit>

QT_USE_NAMESPACE

static const char blankString[] = QT_TRANSLATE_NOOP(
            "SettingsDialog", "N/A"
            );

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    intValidator = new QIntValidator(0, 4000000, this);

    ui->baudRateComboBox->setInsertPolicy(QComboBox::NoInsert);

    connect(ui->applyPushButton, &QPushButton::clicked,
            this,&SettingsDialog::apply);
    connect(ui->serialPortInfoListBox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged)
            , this, &SettingsDialog::showPortInfo);
    connect(ui->baudRateComboBox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged)
            , this, &SettingsDialog::checkCustomBaudRatePolicy);
    connect(ui->serialPortInfoListBox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged)
            , this, &SettingsDialog::checkCustomDevicePathPolicy);

    fillPortsParameters();
    fillPortInfo();

    updateSettings();

}


SettingsDialog::~SettingsDialog()
{
    delete ui;
}

SettingsDialog::Settings SettingsDialog::settings() const
{
    return currentSettings;
}

void SettingsDialog::showPortInfo(int idx)
{
    if(idx == -1) {
        return;
    }

    QStringList list = ui->serialPortInfoListBox->itemData(idx).toStringList();
    ui->descpiption->setText(tr("%1").arg(list.count() > 1 ? list.at(1) : tr(blankString)));
    ui->Manufacturer->setText(tr("%1").arg(list.count() > 1 ? list.at(2) : tr(blankString)));
    ui->SerialNum->setText(tr("%1").arg(list.count() > 1 ? list.at(3) : tr(blankString)));
    ui->Location->setText(tr("%1").arg(list.count() > 1 ? list.at(4) : tr(blankString)));
    ui->vendorId->setText(tr("%1").arg(list.count() > 1 ? list.at(5) : tr(blankString)));
    ui->ProductId->setText(tr("%1").arg(list.count() > 1 ? list.at(6) : tr(blankString)));
}

void SettingsDialog::apply()
{
    updateSettings();
    hide();
}

void SettingsDialog::checkCustomBaudRatePolicy(int idx)
{
    bool isCustommBaudRate = !(ui->baudRateComboBox->itemData(idx).isValid());
    ui->baudRateComboBox->setEditable(isCustommBaudRate);
    if(isCustommBaudRate) {
        ui->baudRateComboBox->clearEditText();
        QLineEdit *edit = ui->baudRateComboBox->lineEdit();
        edit->setValidator(intValidator);
    }
}

void SettingsDialog::checkCustomDevicePathPolicy(int idx)
{
   bool isCustommPath = !(ui->serialPortInfoListBox->itemData(idx).isValid());
   ui->serialPortInfoListBox->setEditable(isCustommPath);
   if(isCustommPath) {
       ui->serialPortInfoListBox->clearEditText();
   }
}

void SettingsDialog::fillPortsParameters()
{
    ui->baudRateComboBox->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
    ui->baudRateComboBox->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
    ui->baudRateComboBox->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
    ui->baudRateComboBox->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);

    ui->dataBitsComboBox->addItem(QStringLiteral("5"), QSerialPort::Data5);
    ui->dataBitsComboBox->addItem(QStringLiteral("6"), QSerialPort::Data6);
    ui->dataBitsComboBox->addItem(QStringLiteral("7"), QSerialPort::Data7);
    ui->dataBitsComboBox->addItem(QStringLiteral("8"), QSerialPort::Data8);
    ui->dataBitsComboBox->setCurrentIndex(3);

    ui->parityComboBox->addItem(tr("None"), QSerialPort::NoParity);
    ui->parityComboBox->addItem(tr("Even"), QSerialPort::EvenParity);
    ui->parityComboBox->addItem(tr("odd"), QSerialPort::OddParity);
    ui->parityComboBox->addItem(tr("Mark"), QSerialPort::MarkParity);
    ui->parityComboBox->addItem(tr("Space"), QSerialPort::SpaceParity);

    ui->stopBitsComboBox->addItem(QStringLiteral("1"), QSerialPort::OneStop);
  #ifdef Q_OS_WIN
      ui->stopBitsComboBox->addItem(tr("1.5"), QSerialPort::OneAndHalfStop);
  #endif
      ui->stopBitsComboBox->addItem(QStringLiteral("2"), QSerialPort::TwoStop);

      ui->flowControlComboBox->addItem(tr("None"), QSerialPort::NoFlowControl);
      ui->flowControlComboBox->addItem(tr("RTS/CTS"), QSerialPort::HardwareControl);
      ui->flowControlComboBox->addItem(tr("XON/XOFF"), QSerialPort::SoftwareControl);

}

void SettingsDialog::fillPortInfo()
{
    ui->serialPortInfoListBox->clear();
    QString description;
    QString manufacturer;
    QString serialNumber;
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos) {
        QStringList list;
        description = info.description();
        manufacturer = info.manufacturer();
        serialNumber = info.serialNumber();
        list << info.portName()
             << (!description.isEmpty() ? description : blankString)
             << (!manufacturer.isEmpty() ? manufacturer : blankString)
             << (!serialNumber.isEmpty() ? serialNumber : blankString)
             << info.systemLocation()
             << (info.vendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : blankString)
             << (info.productIdentifier() ? QString::number(info.productIdentifier(), 16) : blankString);

        ui->serialPortInfoListBox->addItem(list.first(), list);
    }
    ui->serialPortInfoListBox->addItem(tr("Custom"));

}

void SettingsDialog::updateSettings()
{
    currentSettings.name = ui->serialPortInfoListBox->currentText();

          if (ui->baudRateComboBox->currentIndex() == 4) {
              currentSettings.baudRate = ui->baudRateComboBox->currentText().toInt();
          } else {
              currentSettings.baudRate = static_cast<QSerialPort::BaudRate>(
                          ui->baudRateComboBox->itemData(ui->baudRateComboBox->currentIndex()).toInt());
          }
          currentSettings.stringBaudRate = QString::number(currentSettings.baudRate);

          currentSettings.dataBits = static_cast<QSerialPort::DataBits>(
                      ui->dataBitsComboBox->itemData(ui->dataBitsComboBox->currentIndex()).toInt());
          currentSettings.stringDataBits = ui->dataBitsComboBox->currentText();

          currentSettings.parity = static_cast<QSerialPort::Parity>(
                      ui->parityComboBox->itemData(ui->parityComboBox->currentIndex()).toInt());
          currentSettings.stringParity = ui->parityComboBox->currentText();

          currentSettings.stopBits = static_cast<QSerialPort::StopBits>(
                      ui->stopBitsComboBox->itemData(ui->stopBitsComboBox->currentIndex()).toInt());
          currentSettings.stringStopBits = ui->stopBitsComboBox->currentText();

          currentSettings.flowControl = static_cast<QSerialPort::FlowControl>(
                      ui->flowControlComboBox->itemData(ui->flowControlComboBox->currentIndex()).toInt());
          currentSettings.stringFlowControl = ui->flowControlComboBox->currentText();

          currentSettings.localEchoEnabled = ui->localEchocheckBox->isChecked();
}
