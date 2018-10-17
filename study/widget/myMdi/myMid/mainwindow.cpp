#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mid_child.h"
#include <QMdiSubWindow>
#include <QFileDialog>
#include <QCloseEvent>
#include <QSettings>

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

    windowMapper = new QSignalMapper(this);
    connect(windowMapper, SIGNAL(mapped(QWidget*)), this, SLOT(setActiveSubWindow(QWidget*)));
    updateWindowMenu();
    connect(ui->menu_W, SIGNAL(aboutToShow()), this, SLOT(updateWindowMenu()));

    readSettings();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    ui->mdiArea->closeAllSubWindows();
    if(ui->mdiArea->currentSubWindow()) {
        event->ignore();
    } else {
        writeSettings();
        event->accept();
    }
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

void MainWindow::readSettings()
{
    QSettings settints("file", "myMdi");
    QPoint pos = settints.value("pos", QPoint(200, 200)).toPoint();
    QSize size = settints.value("size", QSize(400, 400)).toSize();
    move(pos);
    resize(size);
}

void MainWindow::writeSettings()
{
    QSettings settints("file", "myMdi");
    settints.setValue("pos", pos());
    settints.setValue("size", size());
}

void MainWindow::initWindow()
{
    setWindowTitle(tr(""));
    ui->mainToolBar->setWindowTitle(tr(""));
    ui->mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);


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

void MainWindow::updateWindowMenu()
{
    ui->menu_W->clear();
    ui->menu_W->addAction(ui->actionClose);
    ui->menu_W->addAction(ui->actionCloseAll);
    ui->menu_W->addSeparator();
    ui->menu_W->addAction(ui->actionTile);
    ui->menu_W->addAction(ui->actionCascade);
    ui->menu_W->addSeparator();
    ui->menu_W->addAction(ui->actionNext);
    ui->menu_W->addAction(ui->actionPrevious);
    ui->menu_W->addSeparator();

    QList<QMdiSubWindow *> windows = ui->mdiArea->subWindowList();
    actionSeperator->setVisible(! windows.isEmpty());

    for(int i = 0; i < windows.size(); i++) {
        MidChild *child = qobject_cast<MidChild *>(windows.at(i)->widget());
        QString text;
        if(i < 9) {
            text = tr("&%1 %2")
                    .arg(i + 1)
                    .arg(child->userFirendlyCurrentFile());
        } else {
            text = tr("%1 %2")
                    .arg(i + 1)
                    .arg(child->userFirendlyCurrentFile());
        }

        QAction *action = ui->menu_W->addAction(text);
        action->setCheckable(true);
        action->setChecked(child == activeMdiChild());
        connect(action, SIGNAL(triggered(bool)), windowMapper, SLOT(map()));
        windowMapper->setMapping(action, windows.at(i));
    }
}

void MainWindow::on_actionSave_triggered()
{
    if(activeMdiChild() && activeMdiChild()->save()) {
        ui->statusBar->showMessage(tr("文件保存成功"), 2000);
    }
}

void MainWindow::on_actionUndo_triggered()
{
    if(activeMdiChild()) {
        activeMdiChild()->undo();
    }
}

void MainWindow::on_actionClose_triggered()
{
    ui->mdiArea->closeActiveSubWindow();;
}

void MainWindow::on_actionExit_triggered()
{
    qApp->closeAllWindows();
}

void MainWindow::showTextRowAndCol()
{
    if(activeMdiChild()) {
        int rowNum = activeMdiChild()->textCursor()
                .blockNumber() + 1;
        int colNum = activeMdiChild()->textCursor()
                .columnNumber() + 1;
        ui->statusBar->showMessage(tr("%1%2")
                                   .arg(rowNum)
                                   .arg(colNum));
    }
}
