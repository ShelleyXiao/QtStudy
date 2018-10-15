#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QPushButton>
#include <QFileDialog>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->isUntitled = false;
    this->curFile = tr("未命名.txt");

    this->setWindowTitle(curFile);
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
        box.setWindowTitle(tr("警告"));
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("尚未保存，是否保存?"));
        QPushButton *yesBtn = box.addButton(tr("是(&Y)"), QMessageBox::YesRole);
        QPushButton *noBtn = box.addButton(tr("否(&N)"), QMessageBox::NoRole);

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
    QString fileName = QFileDialog::getSaveFileName(this,tr("另存为"),
                                                    curFile);

    if(fileName.isEmpty()) {
        return false;
    }

    return saveFile(fileName);

}

bool MainWindow::saveFile(const QString &fileName) {
    QFile file(fileName);

    if(!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("多文档编辑器"), tr("无法写入%1: /n %2")
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
        QMessageBox::warning(this, tr("多文档编辑器"), tr("无法读取文件")
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

void MainWindow::closeEvent(QCloseEvent *event) {
    if(maybeSave()) {
        event->accept();
    } else {
        event->ignore();
    }
}
