#ifndef TETRIXBOARD_H
#define TETRIXBOARD_H

#include <QBasicTimer>
#include <QFrame>
#include <QPointer>

#include "tetrixpiece.h"

QT_BEGIN_NAMESPACE
class QLabel;
QT_END_NAMESPACE

class TetrixBoard : public QFrame
{
    Q_OBJECT

public:
    TetrixBoard(QWidget *parent = 0);

    void setNextPieceLabel(QLabel *label);
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

public slots:
    void start();
    void pause();

signals:
    void scoreChanged(int score);
    void levelChanged(int level);
    void linesRemovedChanged(int numLines);

protected:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *event);

private:
    enum {BoardWidth = 10, BoardHeight = 22};

    TetrixShape &shapeAt(int x, int y) {
        return board[(y * BoardWidth) + x];
    }

    int timeoutTime() {
        return 1000 / ( 1 + level);
    }

    int squareWidth() {
        return contentsRect().width() / BoardWidth;
    }

    int squareHeight() {
        return contentsRect().height() / BoardHeight;
    }


    void clearBoard();
    void dropDown();
    void oneLineDown();
    void pieceDropped(int dropHeight);
    void removeFulllines();
    void newPiece();
    void showNextPiece();
    bool tryMove(const TetrixPiece &piece, int newX, int newY);
    void drawSquare(QPainter &painter, int x ,int y, TetrixShape shape);


    QBasicTimer timer;
    QPointer<QLabel> nextPieceLabel;
    bool isStarted;
    bool isPaused;
    bool isWaitingAfterLine;
    TetrixPiece curPiece;
    TetrixPiece nextPiece;

    int curX;
    int curY;
    int numLinesRemoved;
    int numPieceDropped;
    int score;
    int level;
    TetrixShape board[BoardHeight * BoardWidth];

};

#endif // TETRIXBOARD_H
