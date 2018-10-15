#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mid_child.h"
#include <QMdiSubWindow>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    actionSeperator = new QAction(this);
    actionSeperator->setSeparator(true);

    updateMenus();
    connect(ui->mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)),
            this, SLOT(updateMenus()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    MidChild *child = createMdiChild();
    child->newFile();
    child->show();

}

void MainWindow::updateMenus()
{
    bool hasMdiChild = (activeMdiChild() != 0);
    ui->actionSave->setEnabled(hasMdiChild);
    ui->actionSaveAs->setEnabled(hasMdiChild);
    ui->actionPaste->setEnabled(hasMdiChild);
    ui->actionClose->setEnabled(hasMdiChild);
    ui->actionCloseAll->setEnabled(hasMdiChild);
    ui->actionTile->setEnabled(hasMdiChild);
    ui->actionCascade->setEnabled(hasMdiChild);
    ui->actionNext->setEnabled(hasMdiChild);
    ui->actionPrevious->setEnabled(hasMdiChild);

    actionSeperator->setVisible(hasMdiChild);

    bool hasSelection = (activeMdiChild() && activeMdiChild()->textCursor().hasSelection());

    ui->actionCut->setEnabled(hasSelection);
    ui->actionCopy->setEnabled(hasSelection);

    ui->actionUndo->setEnabled(activeMdiChild() && activeMdiChild()->document()->isUndoAvailable());

    ui->actionRedo->setEnabled(activeMdiChild() && activeMdiChild()->document()->isUndoAvailable());
}

MidChild *MainWindow::createMdiChild()
{
    MidChild *child = new MidChild;
    ui->mdiArea->addSubWindow(child);

    connect(child, SIGNAL(copyAvailable(bool)), ui->actionCut, SLOT(setEnabled(bool)));
    connect(child, SIGNAL(copyAvailable(bool)), ui->actionCopy, SLOT(setEnabled(bool)));
    connect(child->document(), SIGNAL(undoAvailable(bool)), ui->actionUndo, SLOT(setEnabled(bool)));
    connect(child->document(), SIGNAL(redoAvailable(bool)), ui->actionRedo, SLOT(setEnabled(bool)));

    return child;
}

void MainWindow::setActiveSubWindow(QWidget *window)
{
    if(!window) {
        return;
    }
    ui->mdiArea->setActiveSubWindow(qobject_cast<QMdiSubWindow *>(window));
}

MidChild *MainWindow::activeMdiChild()
{
    if(QMdiSubWindow *activeSubWindow = ui->mdiArea->activeSubWindow()) {
        return qobject_cast<MidChild *>(activeSubWindow->widget());
    }
    return 0;
}

QMdiSubWindow *MainWindow::findMdiChild(const QString &fileName)
{
    QString canonicalFilePath = QFileInfo(fileName).canonicalFilePath();
    foreach(QMdiSubWindow *window, ui->mdiArea->subWindowList()) {
        MidChild *mdiChild = qobject_cast<MidChild *>(window->widget());
        if(mdiChild->currentFile() == canonicalFilePath) {
            return window;
        }
    }

    return 0;
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty()) {
        QMdiSubWindow *exiting = findMdiChild(fileName);
        if(exiting) {
            ui->mdiArea->setActiveSubWindow(exiting);
            return;
        }

        MidChild *child = createMdiChild();
        if(child->loadFile(fileName)) {
            ui->statusBar->showMessage(tr("打开文件成功"), 2000);
            child->show();
        } else {
            child->close();
        }
    }
}
