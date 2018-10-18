#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFrame>
#include <QWidget>

QT_BEGIN_NAMESPACE

class QLCDNumber;
class QLabel;
class QPushButton;

QT_END_NAMESPACE

class TetrixBoard;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();

private:
    QLabel *createLabel(const QString &text);

    TetrixBoard *board;

    QLabel *nextPieceLabel;
    QLCDNumber *scoreLcd;
    QLCDNumber *levelLcd;
    QLCDNumber *linesLcd;
    QPushButton *startButton;
    QPushButton *quitButton;
    QPushButton *pauseButton;
};

#endif // MAINWINDOW_H
