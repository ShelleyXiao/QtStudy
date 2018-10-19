#ifndef MYVIEW_H
#define MYVIEW_H

#include <QGraphicsView>



class BoxGroup;

class MyView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MyView( QWidget *parent = 0);
public slots:
    void startGame();
    void clearFullRows();
    void moveBox();
    void gameover();


    void restartGame();
    void finishGame();
    void pauseGame();
    void returnGame();

protected:
    void keyPressEvent(QKeyEvent *event);

private:

    void initView();
    void initGame();

    void updateScore(const int fullRowNum = 0);

    BoxGroup *boxGroup;
    BoxGroup *nextBoxGroup;

    QGraphicsLineItem *topLine;
    QGraphicsLineItem *bottomLine;
    QGraphicsLineItem *leftLine;
    QGraphicsLineItem *rightLine;

    QGraphicsTextItem *gameScoreText;
    QGraphicsTextItem *gameLevelText;

    QGraphicsTextItem *gameWelcomeText;
    QGraphicsTextItem *gamePauseText;
    QGraphicsTextItem *gameOverText;

    QGraphicsWidget *maskWidget;

    QGraphicsWidget *startButton;
    QGraphicsWidget *finishButton;
    QGraphicsWidget *restartButton;
    QGraphicsWidget *pauseButton;
    QGraphicsWidget *optionButton;
    QGraphicsWidget *returnButton;
    QGraphicsWidget *helpButton;
    QGraphicsWidget *exitButton;
    QGraphicsWidget *showMenuButton;


    qreal gameSpeed;
    QList<int> rows;



};

#endif // MYVIEW_H
