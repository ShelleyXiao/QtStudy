#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
class QLabel;
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow();
//    ~MainWindow();

private:

    QLabel *createLabel(const QString &text);
};

#endif // MAINWINDOW_H
