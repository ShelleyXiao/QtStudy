#ifndef MYVIEW_H
#define MYVIEW_H

#include <QGraphicsView>
#include <QWidget>

class MyView : public QGraphicsView {

public:
//    MyView();
     explicit MyView(QWidget *parent = 0);
    ~MyView();

protected:
    void wheelEvent(QWheelEvent *event);
    void mousePressEvent(QMouseEvent *event);

    void keyPressEvent(QKeyEvent *event);

};


#endif // MYVIEW_H
