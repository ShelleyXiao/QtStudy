#include "boxgroup.h"
#include "onebox.h"

#include <QKeyEvent>
#include <QTimer>
#include <QDebug>

BoxGroup::BoxGroup()
{
    setFlags(QGraphicsItem::ItemIsFocusable);
    oldTransform = transform();
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(moveOneStep()));
    currentShape = RandomShape;
}

QRectF BoxGroup::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(-40 - penWidth / 2 , -40 - penWidth / 2,
                  80 + penWidth, 80 + penWidth);
}

bool BoxGroup::isColliding()
{
    QList<QGraphicsItem *> itemList = childItems();
    QGraphicsItem *item;
    foreach(item , itemList) {
        if(item->collidingItems().count() > 1) {
            return true;
        }
    }

    return false;
}

bool BoxGroup::createBox(const QPointF &point, BoxGroup::BoxShape shape)
{
    static const QColor colorTable[7] = {
                QColor(200, 0, 0, 100), QColor(255, 200, 0, 100),
                QColor(0, 0, 200, 100), QColor(0, 200, 0, 100),
                QColor(0, 200, 255, 100), QColor(200, 0, 255, 100),
                QColor(150, 100, 100, 100)
    };

    int shapeId = shape;
    if(shape == RandomShape) {
        shapeId = qrand() % 7;
    }

    QColor color = colorTable[shapeId];
    QList<OneBox *> list;
    setTransform(oldTransform);
    for(int i = 0; i < 4 ;i++) {
        OneBox *temp = new OneBox(color);
        list << temp;
        addToGroup(temp);;
    }

    switch (shapeId) {
    case IShape:
         currentShape = IShape;
         list.at(0)->setPos(-30, -10);
         list.at(1)->setPos(-10, -10);
         list.at(2)->setPos(10, -10);
         list.at(3)->setPos(30, -10);
        break;

    case JShape :
            currentShape = JShape;
            list.at(0)->setPos(10, -10);
            list.at(1)->setPos(10, 10);
            list.at(2)->setPos(-10, 30);
            list.at(3)->setPos(10, 30);
            break;

        case LShape :
            currentShape = LShape;
            list.at(0)->setPos(-10, -10);
            list.at(1)->setPos(-10, 10);
            list.at(2)->setPos(-10, 30);
            list.at(3)->setPos(10, 30);
            break;

        case OShape :
            currentShape = OShape;
            list.at(0)->setPos(-10, -10);
            list.at(1)->setPos(10, -10);
            list.at(2)->setPos(-10, 10);
            list.at(3)->setPos(10, 10);
            break;

        case SShape :
            currentShape = SShape;
            list.at(0)->setPos(10, -10);
            list.at(1)->setPos(30, -10);
            list.at(2)->setPos(-10, 10);
            list.at(3)->setPos(10, 10);
            break;

        case TShape :
            currentShape = TShape;
            list.at(0)->setPos(-10, -10);
            list.at(1)->setPos(10, -10);
            list.at(2)->setPos(30, -10);
            list.at(3)->setPos(10, 10);
            break;

        case ZShape :
            currentShape = ZShape;
            list.at(0)->setPos(-10, -10);
            list.at(1)->setPos(10, -10);
            list.at(2)->setPos(10, 10);
            list.at(3)->setPos(30, 10);
            break;


    default:
        break;
    }

    setPos(point);
    if(isColliding()) {
        stopTimer();
        qDebug() << "测试";
        emit gameFinished();
    }
}

void BoxGroup::clearBoxGroup(bool destroyBo)
{
    QList<QGraphicsItem *> itemList = childItems();
    foreach(QGraphicsItem *item, itemList) {
        removeFromGroup(item);
        if(destroyBo) {
            OneBox *box = (OneBox *)item;
            box->deleteLater();
        }
    }
}

void BoxGroup::keyPressEvent(QKeyEvent *event)
{

    static qreal angle = 0;

    switch(event->key()) {
        case Qt::Key_Left:
            moveBy(-20, 0);
            if(isColliding()) {
                moveBy(20, 0);
            }
        break;

        case Qt::Key_Right:
        moveBy(20, 0);
        if(isColliding()) {
            moveBy(-20, 0);
        }
        break;

        case Qt::Key_Down:
        moveBy(0, 20);
        if(isColliding()) {
            moveBy(0, -20);
            clearBoxGroup();
            emit needNewBox();
        }
        break;

        case Qt::Key_Up:
            setRotation(angle+90.0);
            angle += 90;
            if(isColliding()) {
                setRotation(angle-90.0);
                angle -= 90;
            }

        break;

        case Qt::Key_Space:
            moveBy(0, 20);
            while(! isColliding()) {
                moveBy(0, 20);
            }
            clearBoxGroup();
            emit needNewBox();
        break;

    default:
        break;
    }
}

void BoxGroup::moveOneStep()
{
    moveBy(0, 20);
    if(isColliding()) {
        moveBy(0, -20);
        clearBoxGroup();
        emit needNewBox();
    }
}

void BoxGroup::startTimer(int interval)
{
    timer->start(interval);
}

void BoxGroup::stopTimer()
{
    timer->stop();
}
