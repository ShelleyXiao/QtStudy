#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QPushButton>
#include <QFileDialog>
#include <QTextStream>
#include <QLineEdit>
#include <QDialog>
#include <QPushButton>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->isUntitled = false;
    this->curFile = QString::fromLocal8Bit("未命名.txt");

    this->setWindowTitle(curFile);

    this->findDlg = new QDialog(this);
    findDlg->setWindowTitle(QString::fromLocal8Bit("查找"));
    QPushButton *btn = new QPushButton(QString::fromLocal8Bit("查找下一个"), findDlg);
    QVBoxLayout *layout = new QVBoxLayout(findDlg);
    findLineEdit = new QLineEdit(findDlg);
    layout->addWidget(findLineEdit);
    layout->addWidget(btn);
    connect(btn, SIGNAL(clicked()), this, SLOT(showFindText()));

//    ui->statusBar->showMessage(QString::fromLocal8Bit("qt"), 2000);

    this->statusLabel = new QLabel();
    statusLabel->setMinimumSize(150, 20);
    statusLabel->setFrameShape(QFrame::WinPanel);
    statusLabel->setFrameShadow(QFrame::Sunken);
    ui->statusBar->addWidget(statusLabel);
    statusLabel->setText(QString::fromLocal8Bit("qt welcome"));

    QLabel *permanent = new QLabel;
    permanent->setFrameStyle(QFrame::Box | QFrame::Sunken);
    permanent->setText(tr("<a href=\"www.baidu.com\">hello</a>"));
    permanent->setTextFormat(Qt::RichText);
    permanent->setOpenExternalLinks(true);
    ui->statusBar->addPermanentWidget(permanent);
}


void MainWindow::newFile() {
    if(maybeSave()) {
        isUntitled = true;
        curFile = tr("未命名.txt");
        ui->textEdit->clear();
        this->setWindowTitle(curFile);
    }
}

bool MainWindow::maybeSave() {

    if(ui->textEdit->document()->isModified()) {
        QMessageBox box;
        box.setWindowTitle(QString::fromLocal8Bit("警告"));
        box.setIcon(QMessageBox::Warning);
        box.setText(QString::fromLocal8Bit("尚未保存，是否保存?"));
        QPushButton *yesBtn = box.addButton(QString::fromLocal8Bit("是(&Y)"), QMessageBox::YesRole);
        QPushButton *noBtn = box.addButton(QString::fromLocal8Bit("否(&N)"), QMessageBox::NoRole);

        box.exec();

        if(box.clickedButton() == yesBtn) {
            return save();
        } else if(box.clickedButton() == noBtn) {
            return false;
        }
    }

    return true;
}

bool MainWindow::save() {
    if(isUntitled) {
        return saveAs();
    } else {
        return saveFile(curFile);
    }

}

bool MainWindow::saveAs() {
    QString fileName = QFileDialog::getSaveFileName(this,QString::fromLocal8Bit("另存为"),
                                                    curFile);

    if(fileName.isEmpty()) {
        return false;
    }

    return saveFile(fileName);

}

bool MainWindow::saveFile(const QString &fileName) {
    QFile file(fileName);

    if(!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, QString::fromLocal8Bit("多文档编辑器"), QString::fromLocal8Bit("无法写入%1: /n %2")
                             .arg(fileName)
                             .arg(file.errorString()));
        return false;
    }
    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << ui->textEdit->toPlainText();
    QApplication::restoreOverrideCursor();

    curFile = QFileInfo(fileName).canonicalFilePath();
    setWindowTitle(curFile);

    return true;
}

bool MainWindow::loadFile(const QString &fileName) {
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, QString::fromLocal8Bit("多文档编辑器"), QString::fromLocal8Bit("无法读取文件")
                             .arg(fileName)
                             .arg(file.errorString()));
        return false;
    }

    QTextStream in(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    ui->textEdit->setPlainText(in.readAll());
    QApplication::restoreOverrideCursor();

    curFile = QFileInfo(file).canonicalFilePath();
    setWindowTitle(curFile);

    return true;
}

MainWindow::~MainWindow()
{
    delete     findLineEdit;
    delete     findDlg;
    delete     statusLabel;
    delete ui;
}

void MainWindow::on_action_New_triggered()
{
    newFile();
}

void MainWindow::on_action_Save_triggered()
{
    save();
}

void MainWindow::on_action_SaveAs_triggered()
{
    saveAs();
}

void MainWindow::on_action_Open_triggered()
{
    if(maybeSave()) {
        QString fileName = QFileDialog::getOpenFileName(this);

        if(!fileName.isEmpty()) {
            loadFile(fileName);
            ui->textEdit->setVisible(true);
        }
    }
}

void MainWindow::on_action_Close_triggered()
{
    if(maybeSave()) {
        ui->textEdit->setVisible(false);
    }
}



void MainWindow::on_action_Exit_triggered()
{
    on_action_Close_triggered();
    qApp->quit();
}



void MainWindow::on_action_Paste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_action_Undo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_action_Copy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_action_Cut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::showFindText()
{
    QString str = findLineEdit->text();
//    printf("%s", qPrintable(str));
    if(!ui->textEdit->find(str, QTextDocument::FindBackward)) {
        QMessageBox::warning(this, QString::fromLocal8Bit("查找"), QString::fromLocal8Bit("找不到%1").arg(str));
    }
}

void MainWindow::closeEvent(QCloseEvent *event) {
    if(maybeSave()) {
        event->accept();
    } else {
        event->ignore();
    }
}

void MainWindow::on_action_Find_triggered()
{
    findDlg->show();
}
