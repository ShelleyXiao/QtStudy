#include "widget.h"
#include "ui_widget.h"

#include "mydialog.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    MyDialog *dialog = new MyDialog(this);
    connect(dialog, SIGNAL(dlgReturn(int)), this, SLOT(showValue(int)));
    dialog->show();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::showValue(int val)
{
    ui->label->setText(tr("%1").arg(val));
}
