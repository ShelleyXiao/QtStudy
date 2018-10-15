/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *hostLineEdit;
    QLineEdit *portLineEdit;
    QProgressBar *clientProgressBar;
    QLabel *statusLable;
    QLabel *clientStatusLable;
    QPushButton *openButton;
    QPushButton *sendButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(400, 300);
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 50, 54, 12));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 100, 54, 12));
        hostLineEdit = new QLineEdit(Widget);
        hostLineEdit->setObjectName(QStringLiteral("hostLineEdit"));
        hostLineEdit->setGeometry(QRect(90, 50, 241, 20));
        portLineEdit = new QLineEdit(Widget);
        portLineEdit->setObjectName(QStringLiteral("portLineEdit"));
        portLineEdit->setGeometry(QRect(90, 100, 241, 20));
        clientProgressBar = new QProgressBar(Widget);
        clientProgressBar->setObjectName(QStringLiteral("clientProgressBar"));
        clientProgressBar->setGeometry(QRect(40, 160, 331, 23));
        clientProgressBar->setValue(0);
        statusLable = new QLabel(Widget);
        statusLable->setObjectName(QStringLiteral("statusLable"));
        statusLable->setGeometry(QRect(30, 220, 54, 12));
        clientStatusLable = new QLabel(Widget);
        clientStatusLable->setObjectName(QStringLiteral("clientStatusLable"));
        clientStatusLable->setGeometry(QRect(70, 220, 54, 12));
        openButton = new QPushButton(Widget);
        openButton->setObjectName(QStringLiteral("openButton"));
        openButton->setGeometry(QRect(40, 250, 75, 23));
        sendButton = new QPushButton(Widget);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setGeometry(QRect(240, 250, 75, 23));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "\344\270\273\346\234\272", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "\347\253\257\345\217\243", Q_NULLPTR));
        statusLable->setText(QApplication::translate("Widget", "\347\212\266\346\200\201:", Q_NULLPTR));
        clientStatusLable->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        openButton->setText(QApplication::translate("Widget", "\346\211\223\345\274\200", Q_NULLPTR));
        sendButton->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
