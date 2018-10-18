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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonFixed;
    QPushButton *pushButtonPreferred;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonPreferred2;
    QPushButton *pushButtonMinimum;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonMinimum2;
    QPushButton *pushButtonExpanding;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(400, 300);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonFixed = new QPushButton(Widget);
        pushButtonFixed->setObjectName(QStringLiteral("pushButtonFixed"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonFixed->sizePolicy().hasHeightForWidth());
        pushButtonFixed->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButtonFixed);

        pushButtonPreferred = new QPushButton(Widget);
        pushButtonPreferred->setObjectName(QStringLiteral("pushButtonPreferred"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButtonPreferred->sizePolicy().hasHeightForWidth());
        pushButtonPreferred->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pushButtonPreferred);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButtonPreferred2 = new QPushButton(Widget);
        pushButtonPreferred2->setObjectName(QStringLiteral("pushButtonPreferred2"));
        sizePolicy1.setHeightForWidth(pushButtonPreferred2->sizePolicy().hasHeightForWidth());
        pushButtonPreferred2->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(pushButtonPreferred2);

        pushButtonMinimum = new QPushButton(Widget);
        pushButtonMinimum->setObjectName(QStringLiteral("pushButtonMinimum"));

        horizontalLayout_2->addWidget(pushButtonMinimum);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButtonMinimum2 = new QPushButton(Widget);
        pushButtonMinimum2->setObjectName(QStringLiteral("pushButtonMinimum2"));

        horizontalLayout_3->addWidget(pushButtonMinimum2);

        pushButtonExpanding = new QPushButton(Widget);
        pushButtonExpanding->setObjectName(QStringLiteral("pushButtonExpanding"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButtonExpanding->sizePolicy().hasHeightForWidth());
        pushButtonExpanding->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(pushButtonExpanding);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        pushButtonFixed->setText(QApplication::translate("Widget", "Fixed", Q_NULLPTR));
        pushButtonPreferred->setText(QApplication::translate("Widget", "Preferred", Q_NULLPTR));
        pushButtonPreferred2->setText(QApplication::translate("Widget", "Preferred2", Q_NULLPTR));
        pushButtonMinimum->setText(QApplication::translate("Widget", "Minimum", Q_NULLPTR));
        pushButtonMinimum2->setText(QApplication::translate("Widget", "Minimum2", Q_NULLPTR));
        pushButtonExpanding->setText(QApplication::translate("Widget", "Expanding", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
