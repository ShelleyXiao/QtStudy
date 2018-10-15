#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QMessageBox>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QSqlTableModel(this);
    model->setTable("student");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    model->database().transaction();
    if(model->submitAll())
    {
        model->database().commit();

    }
    else
    {
        model->database().rollback();
        QMessageBox::warning(this, tr(""),
                            tr("%1").arg(model->lastError().text()));
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    model->revertAll();
}

void MainWindow::on_pushButton_7_clicked()
{
    QString name = ui->lineEdit->text();
    model->setFilter(QString("name = '%1'").arg(name));
    model->select();
}

void MainWindow::on_pushButton_8_clicked()
{
    model->setTable("student");;
    model->select();
}

void MainWindow::on_pushButton_5_clicked()
{
    model->setSort(0, Qt::AscendingOrder);
    model->select();
}

void MainWindow::on_pushButton_6_clicked()
{
    model->setSort(0, Qt::DescendingOrder);
    model->select();
}

void MainWindow::on_pushButton_3_clicked()
{
    int rowNum = model->rowCount();
    int id = 10;
    model->insertRow(rowNum);
    model->setData(model->index(rowNum, 0), id);
}

void MainWindow::on_pushButton_4_clicked()
{
    int curRow = ui->tableView->currentIndex().row();
    model->removeRow(curRow);
    int ok = QMessageBox::warning(this, tr(""), tr(""),
                                  QMessageBox::Yes,QMessageBox::Ok);
    if(ok == QMessageBox::No)
    {
        model->revertAll();
    }
    else
    {
        model->submitAll();
    }
}
