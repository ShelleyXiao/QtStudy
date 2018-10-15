#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextBrowser>
#include <QLabel>

#include "boardlayout.h"

MainWindow::MainWindow()
{
    QTextBrowser *centralWidget = new QTextBrowser;
    centralWidget->setPlainText(tr("Central widget"));

    BoradLayout *layout = new BoradLayout;
    layout->addWidget(centralWidget, BoradLayout::Center);
    layout->addWidget(createLabel("North"), BoradLayout::North);
    layout->addWidget(createLabel("West"), BoradLayout::West);
    layout->addWidget(createLabel("East 1"), BoradLayout::East);
    layout->addWidget(createLabel("East 2") , BoradLayout::East);
    layout->addWidget(createLabel("South"), BoradLayout::South);
    setLayout(layout);

    setWindowTitle(tr("Border Layout"));
}



QLabel *MainWindow::createLabel(const QString &text)
{
    QLabel *label = new QLabel(text);
    label->setFrameStyle(QFrame::Box | QFrame::Raised);
    return label;
}

