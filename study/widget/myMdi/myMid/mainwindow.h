#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mid_child.h"
#include <QMdiSubWindow>

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

private slots:
    void on_actionNew_triggered();

    void updateMenus();

    MidChild *createMdiChild();

    void setActiveSubWindow(QWidget *window);

    void on_actionOpen_triggered();

private:
    Ui::MainWindow *ui;

    QAction *actionSeperator;

    MidChild *activeMdiChild();

    QMdiSubWindow *findMdiChild(const QString &fileName);
};

#endif // MAINWINDOW_H
