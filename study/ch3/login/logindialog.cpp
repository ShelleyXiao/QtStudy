#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->pwdLineEdit->setEchoMode(QLineEdit::Password);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_loginBtn_clicked()
{
    if(ui->userLineEdit->text().trimmed() == tr("xiaoyunlu")
            && ui->pwdLineEdit->text() == tr("123456")) {
        accept();
    } else {
        QMessageBox::warning(this, tr("Warning"),
                             tr("user name or password error!"), QMessageBox::Yes);

        ui->pwdLineEdit->clear();
        ui->userLineEdit->clear();
        ui->userLineEdit->setFocus();
    }
}
