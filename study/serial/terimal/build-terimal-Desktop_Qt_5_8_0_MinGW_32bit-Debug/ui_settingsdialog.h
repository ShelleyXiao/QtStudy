/********************************************************************************
** Form generated from reading UI file 'settingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QGridLayout *gridLayout;
    QGroupBox *selectBox;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QComboBox *serialPortInfoListBox;
    QHBoxLayout *horizontalLayout;
    QLabel *descripionLabel;
    QLabel *descpiption;
    QHBoxLayout *horizontalLayout_2;
    QLabel *ManufacturerLabel;
    QLabel *Manufacturer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *SerialNumLabel;
    QLabel *SerialNum;
    QHBoxLayout *horizontalLayout_4;
    QLabel *LocationLabel;
    QLabel *Location;
    QHBoxLayout *horizontalLayout_5;
    QLabel *vendorLabel;
    QLabel *vendorId;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QLabel *ProductId;
    QGroupBox *parametersBox;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *BaudRateLabel;
    QComboBox *baudRateComboBox;
    QHBoxLayout *horizontalLayout_8;
    QLabel *DataBitsLabel;
    QComboBox *dataBitsComboBox;
    QHBoxLayout *horizontalLayout_9;
    QLabel *parityLabel;
    QComboBox *parityComboBox;
    QHBoxLayout *horizontalLayout_10;
    QLabel *stopBitsLabel;
    QComboBox *stopBitsComboBox;
    QHBoxLayout *horizontalLayout_11;
    QLabel *fowControlLabel;
    QComboBox *flowControlComboBox;
    QGroupBox *additionalOptionsGroupBox;
    QHBoxLayout *horizontalLayout_13;
    QCheckBox *localEchocheckBox;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer;
    QPushButton *applyPushButton;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName(QStringLiteral("SettingsDialog"));
        SettingsDialog->resize(638, 381);
        gridLayout = new QGridLayout(SettingsDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        selectBox = new QGroupBox(SettingsDialog);
        selectBox->setObjectName(QStringLiteral("selectBox"));
        verticalLayout_2 = new QVBoxLayout(selectBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        serialPortInfoListBox = new QComboBox(selectBox);
        serialPortInfoListBox->setObjectName(QStringLiteral("serialPortInfoListBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(serialPortInfoListBox->sizePolicy().hasHeightForWidth());
        serialPortInfoListBox->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(serialPortInfoListBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        descripionLabel = new QLabel(selectBox);
        descripionLabel->setObjectName(QStringLiteral("descripionLabel"));

        horizontalLayout->addWidget(descripionLabel);

        descpiption = new QLabel(selectBox);
        descpiption->setObjectName(QStringLiteral("descpiption"));

        horizontalLayout->addWidget(descpiption);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        ManufacturerLabel = new QLabel(selectBox);
        ManufacturerLabel->setObjectName(QStringLiteral("ManufacturerLabel"));

        horizontalLayout_2->addWidget(ManufacturerLabel);

        Manufacturer = new QLabel(selectBox);
        Manufacturer->setObjectName(QStringLiteral("Manufacturer"));

        horizontalLayout_2->addWidget(Manufacturer);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        SerialNumLabel = new QLabel(selectBox);
        SerialNumLabel->setObjectName(QStringLiteral("SerialNumLabel"));

        horizontalLayout_3->addWidget(SerialNumLabel);

        SerialNum = new QLabel(selectBox);
        SerialNum->setObjectName(QStringLiteral("SerialNum"));

        horizontalLayout_3->addWidget(SerialNum);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        LocationLabel = new QLabel(selectBox);
        LocationLabel->setObjectName(QStringLiteral("LocationLabel"));

        horizontalLayout_4->addWidget(LocationLabel);

        Location = new QLabel(selectBox);
        Location->setObjectName(QStringLiteral("Location"));

        horizontalLayout_4->addWidget(Location);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        vendorLabel = new QLabel(selectBox);
        vendorLabel->setObjectName(QStringLiteral("vendorLabel"));

        horizontalLayout_5->addWidget(vendorLabel);

        vendorId = new QLabel(selectBox);
        vendorId->setObjectName(QStringLiteral("vendorId"));

        horizontalLayout_5->addWidget(vendorId);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label = new QLabel(selectBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_6->addWidget(label);

        ProductId = new QLabel(selectBox);
        ProductId->setObjectName(QStringLiteral("ProductId"));

        horizontalLayout_6->addWidget(ProductId);


        verticalLayout->addLayout(horizontalLayout_6);


        verticalLayout_2->addLayout(verticalLayout);


        gridLayout->addWidget(selectBox, 0, 0, 1, 1);

        parametersBox = new QGroupBox(SettingsDialog);
        parametersBox->setObjectName(QStringLiteral("parametersBox"));
        verticalLayout_3 = new QVBoxLayout(parametersBox);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        BaudRateLabel = new QLabel(parametersBox);
        BaudRateLabel->setObjectName(QStringLiteral("BaudRateLabel"));

        horizontalLayout_7->addWidget(BaudRateLabel);

        baudRateComboBox = new QComboBox(parametersBox);
        baudRateComboBox->setObjectName(QStringLiteral("baudRateComboBox"));

        horizontalLayout_7->addWidget(baudRateComboBox);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        DataBitsLabel = new QLabel(parametersBox);
        DataBitsLabel->setObjectName(QStringLiteral("DataBitsLabel"));

        horizontalLayout_8->addWidget(DataBitsLabel);

        dataBitsComboBox = new QComboBox(parametersBox);
        dataBitsComboBox->setObjectName(QStringLiteral("dataBitsComboBox"));

        horizontalLayout_8->addWidget(dataBitsComboBox);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        parityLabel = new QLabel(parametersBox);
        parityLabel->setObjectName(QStringLiteral("parityLabel"));

        horizontalLayout_9->addWidget(parityLabel);

        parityComboBox = new QComboBox(parametersBox);
        parityComboBox->setObjectName(QStringLiteral("parityComboBox"));

        horizontalLayout_9->addWidget(parityComboBox);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        stopBitsLabel = new QLabel(parametersBox);
        stopBitsLabel->setObjectName(QStringLiteral("stopBitsLabel"));

        horizontalLayout_10->addWidget(stopBitsLabel);

        stopBitsComboBox = new QComboBox(parametersBox);
        stopBitsComboBox->setObjectName(QStringLiteral("stopBitsComboBox"));

        horizontalLayout_10->addWidget(stopBitsComboBox);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        fowControlLabel = new QLabel(parametersBox);
        fowControlLabel->setObjectName(QStringLiteral("fowControlLabel"));

        horizontalLayout_11->addWidget(fowControlLabel);

        flowControlComboBox = new QComboBox(parametersBox);
        flowControlComboBox->setObjectName(QStringLiteral("flowControlComboBox"));

        horizontalLayout_11->addWidget(flowControlComboBox);


        verticalLayout_3->addLayout(horizontalLayout_11);


        gridLayout->addWidget(parametersBox, 0, 1, 1, 1);

        additionalOptionsGroupBox = new QGroupBox(SettingsDialog);
        additionalOptionsGroupBox->setObjectName(QStringLiteral("additionalOptionsGroupBox"));
        horizontalLayout_13 = new QHBoxLayout(additionalOptionsGroupBox);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        localEchocheckBox = new QCheckBox(additionalOptionsGroupBox);
        localEchocheckBox->setObjectName(QStringLiteral("localEchocheckBox"));

        horizontalLayout_13->addWidget(localEchocheckBox);


        gridLayout->addWidget(additionalOptionsGroupBox, 1, 0, 1, 2);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalSpacer = new QSpacerItem(318, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer);

        applyPushButton = new QPushButton(SettingsDialog);
        applyPushButton->setObjectName(QStringLiteral("applyPushButton"));

        horizontalLayout_12->addWidget(applyPushButton);


        gridLayout->addLayout(horizontalLayout_12, 2, 0, 1, 2);

        gridLayout->setRowStretch(0, 5);
        gridLayout->setRowStretch(1, 1);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);

        retranslateUi(SettingsDialog);

        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QApplication::translate("SettingsDialog", "Dialog", Q_NULLPTR));
        selectBox->setTitle(QApplication::translate("SettingsDialog", "Select Serial Port", Q_NULLPTR));
        descripionLabel->setText(QApplication::translate("SettingsDialog", "Descpiption:", Q_NULLPTR));
        descpiption->setText(QApplication::translate("SettingsDialog", "TextLabel", Q_NULLPTR));
        ManufacturerLabel->setText(QApplication::translate("SettingsDialog", "Manufacturer:", Q_NULLPTR));
        Manufacturer->setText(QApplication::translate("SettingsDialog", "TextLabel", Q_NULLPTR));
        SerialNumLabel->setText(QApplication::translate("SettingsDialog", "Serial nummber", Q_NULLPTR));
        SerialNum->setText(QApplication::translate("SettingsDialog", "TextLabel", Q_NULLPTR));
        LocationLabel->setText(QApplication::translate("SettingsDialog", "Location:", Q_NULLPTR));
        Location->setText(QApplication::translate("SettingsDialog", "TextLabel", Q_NULLPTR));
        vendorLabel->setText(QApplication::translate("SettingsDialog", "Vender Identifier:", Q_NULLPTR));
        vendorId->setText(QApplication::translate("SettingsDialog", "TextLabel", Q_NULLPTR));
        label->setText(QApplication::translate("SettingsDialog", "Product Identifier:", Q_NULLPTR));
        ProductId->setText(QApplication::translate("SettingsDialog", "TextLabel", Q_NULLPTR));
        parametersBox->setTitle(QApplication::translate("SettingsDialog", "Select Parmeters", Q_NULLPTR));
        BaudRateLabel->setText(QApplication::translate("SettingsDialog", "BaudRate:", Q_NULLPTR));
        DataBitsLabel->setText(QApplication::translate("SettingsDialog", "Data bits:", Q_NULLPTR));
        parityLabel->setText(QApplication::translate("SettingsDialog", "Parity:", Q_NULLPTR));
        stopBitsLabel->setText(QApplication::translate("SettingsDialog", "Stop bits:", Q_NULLPTR));
        fowControlLabel->setText(QApplication::translate("SettingsDialog", "Flow control:", Q_NULLPTR));
        additionalOptionsGroupBox->setTitle(QApplication::translate("SettingsDialog", "Additional options", Q_NULLPTR));
        localEchocheckBox->setText(QApplication::translate("SettingsDialog", "Local echo", Q_NULLPTR));
        applyPushButton->setText(QApplication::translate("SettingsDialog", "Apply", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H
