#include "mid_child.h"

#include <QFile>
#include <QMessageBox>
#include <QFileInfo>
#include <QTextStream>
#include <QApplication>
#include <QFileDialog>
#include <QPushButton>
#include <QCloseEvent>

MidChild::MidChild(QWidget *parent)
    :QTextEdit(parent)
{
    setAttribute(Qt::WA_DeleteOnClose);
    isUntitled = true;
}

void MidChild::newFile()
{
    static int sequenceNumber = 1;
    isUntitled = true;
    curFile = tr("未命名文件%1.txt").arg(sequenceNumber++);
    setWindowTitle(curFile + "[*]" + tr(" - 多文档编辑器"));
    connect(document(), SIGNAL(contentsChanged()), this, SLOT(documentWasModified()));
}

bool MidChild::loadFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("多文档编辑器"),
                             tr("无法读取文件 %1:\n %2")
                             .arg(fileName).arg(file.errorString()));
        return false;
    }

    QTextStream in(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    setPlainText(in.readAll());
    QApplication::restoreOverrideCursor();
    setCurrentFile(fileName);
    connect(document(), SIGNAL(contentsChanged()), this, SLOT(documentWasModified()));
    return true;
}

bool MidChild::save()
{
    if(isUntitled) {
        return saveAs();
    } else {
        return saveFile(curFile);
    }
}

bool MidChild::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("另存为"), curFile);
    if(fileName.isEmpty()) {
        return false;
    } else saveFile(fileName);
}

bool MidChild::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly|QFile::Text)) {
        QMessageBox::warning(this, tr("多文档编辑器"),
                             tr("无法写入文件 %1:\n %2")
                             .arg(fileName).arg(file.errorString()));
        return false;
    }
    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << toPlainText();
    QApplication::restoreOverrideCursor();
    setCurrentFile(fileName);

    return true;
}

QString MidChild::userFirendlyCurrentFile()
{
    return QFileInfo(currentFile()).fileName();
}

void MidChild::closeEvent(QCloseEvent *event)
{
    if(maybeSave()) {
        event->accept();
    } else {
        event->ignore();
    }
}

void MidChild::documentWasModified()
{
    setWindowModified(document()->isModified());
}

bool MidChild::maybeSave()
{
    if(document()->isModified()) {
        QMessageBox box;
        box.setWindowTitle(tr("多文档编辑器"));
        box.setText(tr("是否保存文件%1的更改?").arg(userFirendlyCurrentFile()));
        box.setIcon(QMessageBox::Warning);
        QPushButton *button = box.addButton(tr("&是"), QMessageBox::YesRole);
        box.addButton(tr("&否"), QMessageBox::NoRole);
        QPushButton *cancelButton = box.addButton(tr("&取消"), QMessageBox::RejectRole);
        box.exec();
        if(box.clickedButton() == button) {
            return save();
        } else {
            return false;
        }
    }
    return true;
}

void MidChild::setCurrentFile(const QString &fileName)
{
    curFile = QFileInfo(fileName).canonicalFilePath();
    isUntitled = false;
    document()->setModified(false);
    setWindowModified(false);;
    setWindowTitle(userFirendlyCurrentFile() + "[ * ]");
}
