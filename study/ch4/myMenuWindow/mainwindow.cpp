#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QAction *openAction = new QAction(tr("&open"), this);
    QIcon icon(":/images/fileopen.png");
    openAction->setIcon(icon);
    openAction->setShortcut(QKeySequence(tr("Ctrl+o")));
    ui->menu->addAction(openAction);
}

MainWindow::~MainWindow()
{
    delete ui;
}
