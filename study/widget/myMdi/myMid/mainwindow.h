#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mid_child.h"
#include <QMdiSubWindow>
#include <QSignalMapper>

class MidChild;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_actionNew_triggered();

    void updateMenus();

    MidChild *createMdiChild();

    void setActiveSubWindow(QWidget *window);

    void on_actionOpen_triggered();

    void updateWindowMenu();

    void on_actionSave_triggered();

    void on_actionUndo_triggered();

    void on_actionClose_triggered();

    void on_actionExit_triggered();

    void showTextRowAndCol();

private:
    Ui::MainWindow *ui;

    QSignalMapper *windowMapper;

    QAction *actionSeperator;

    MidChild *activeMdiChild();

    QMdiSubWindow *findMdiChild(const QString &fileName);

    void readSettings();

    void writeSettings();

    void initWindow();

};

#endif // MAINWINDOW_H
