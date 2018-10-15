#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlRelation>
#include <QSqlRelationalDelegate>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QSqlRelationalTableModel(this);
    model->setTable("student");
    model->setRelation(2, QSqlRelation("course", "id", "name"));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Course"));
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
}

MainWindow::~MainWindow()
{
    delete ui;
}
