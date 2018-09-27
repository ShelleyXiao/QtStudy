/********************************************************************************
** Form generated from reading UI file 'nWindows.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NWINDOWS_H
#define UI_NWINDOWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_nWindowsClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *nWindowsClass)
    {
        if (nWindowsClass->objectName().isEmpty())
            nWindowsClass->setObjectName(QStringLiteral("nWindowsClass"));
        nWindowsClass->resize(600, 400);
        centralWidget = new QWidget(nWindowsClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(240, 180, 75, 23));
        nWindowsClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(nWindowsClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        nWindowsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(nWindowsClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        nWindowsClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(nWindowsClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        nWindowsClass->setStatusBar(statusBar);

        retranslateUi(nWindowsClass);

        QMetaObject::connectSlotsByName(nWindowsClass);
    } // setupUi

    void retranslateUi(QMainWindow *nWindowsClass)
    {
        nWindowsClass->setWindowTitle(QApplication::translate("nWindowsClass", "nWindows", Q_NULLPTR));
        pushButton->setText(QApplication::translate("nWindowsClass", "\346\214\211\351\222\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class nWindowsClass: public Ui_nWindowsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NWINDOWS_H
