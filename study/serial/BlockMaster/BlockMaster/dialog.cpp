#include "dialog.h"
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QGridLayout>
#include <QPushButton>

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

QT_USE_NAMESPACE

Dialog::Dialog(QWidget *parent)
    : QDialog(parent),
      transactionCount(0),
      serialPortLabel(new QLabel(tr("Serial Port"))),
      serialPortComboBox(new QComboBox),
      waitResponseLabel(new QLabel(tr("Wait response, msec:"))),
      waitResponseSpinBox(new QSpinBox),
      requestLabel(new QLabel(tr("Request:"))),
      requestLineEdit(new QLineEdit(tr("who are you?"))),
      trafficalLable(new QLabel(tr("No traffic."))),
      statusLabel(new QLabel(tr("Status: not running."))),
      runButton(new QPushButton(tr("Start")))
{
    const auto infos = QSerialPortInfo::availablePorts();
    for(const QSerialPortInfo &info : infos) {
        serialPortComboBox->addItem(info.portName());
    }

    waitResponseSpinBox->setRange(0, 10000);
    waitResponseSpinBox->setValue(100);

    auto mainlayout = new QGridLayout;
    mainlayout->addWidget(serialPortLabel, 0,0);
    mainlayout->addWidget(serialPortComboBox, 0, 1);
    mainlayout->addWidget(waitResponseLabel, 1, 0);
    mainlayout->addWidget(waitResponseSpinBox, 1, 1);
    mainlayout->addWidget(runButton, 0, 2, 2, 1);
    mainlayout->addWidget(requestLabel, 2, 0);
    mainlayout->addWidget(requestLineEdit, 2, 1, 1, 3);
    mainlayout->addWidget(trafficalLable, 3, 0, 1, 4);
    mainlayout->addWidget(statusLabel, 4, 0, 1, 5);

    setLayout(mainlayout);

    setWindowTitle("Blocking Master");
    serialPortComboBox->setFocus();


    connect(runButton, &QPushButton::clicked, this, &Dialog::transaction);
    connect(&thread, &MasterThread::response, this, &Dialog::showResponse);
    connect(&thread, &MasterThread::error, this, &Dialog::processError);
    connect(&thread, &MasterThread::timeout, this, &Dialog::processTimeout);
}

Dialog::~Dialog()
{

}

void Dialog::transaction()
{
    setControlsEnable(true);;
    statusLabel->setText(tr("Status: Runing, connected prot %1")
                         .arg(serialPortComboBox->currentText()));
    thread.transaction(serialPortComboBox->currentText()
                       , waitResponseSpinBox->value(),
                       requestLineEdit->text());
}

void Dialog::showResponse(const QString &s)
{
    setControlsEnable(true);
    trafficalLable->setText(tr("Trafiic, transcation #%1"
                               "\n\r-request: %2"
                               "\n\r-response %3")
                            .arg(++transactionCount)
                            .arg(requestLineEdit->text())
                            .arg(s));
}

void Dialog::processError(const QString &s)
{
    setControlsEnable(true);
    statusLabel->setText(tr("Status: Not running %1")
                         .arg(s));
    trafficalLable->setText(tr("No traffic."));
}

void Dialog::processTimeout(const QString &s)
{
    setControlsEnable(true);
    statusLabel->setText(tr("Status: Not running %1")
                         .arg(s));
    trafficalLable->setText(tr("No traffic."));
}

void Dialog::setControlsEnable(bool enable)
{
    runButton->setEnabled(enable);
    serialPortComboBox->setEnabled(enable);
    waitResponseSpinBox->setEnabled(enable);
    requestLineEdit->setEnabled(enable);
}
