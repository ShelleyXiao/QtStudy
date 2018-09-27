#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setText("窗口");

    dlg = new QDialog(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dlg;
}

void MainWindow::on_pushButton_clicked()
{
    dlg->show();
}
