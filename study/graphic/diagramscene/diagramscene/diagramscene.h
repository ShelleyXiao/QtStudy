#ifndef DIAGRAMSCENE_H
#define DIAGRAMSCENE_H

#include "diagramitem.h"
#include "diagramtextitem.h"

#include <QGraphicsScene>

QT_BEGIN_NAMESPACE

class QGraphicsSceneMouseEvent;
class QMenu;
class QPointF;
class QGraphicsLineItem;
class QFont;
class QGraphicsTextItem;
class QColor;

QT_END_NAMESPACE


class DiagramScene : public QGraphicsScene
{
    Q_OBJECT
public:
    enum Mode{InsertItem, InsertLine, InsertText, MoveItem};
    explicit DiagramScene(QMenu *itemMenu, QObject *parent = 0);

    QFont font() const {
        return mFont;
    }

    QColor textColor() const {
        return mTextColor;
    }

    QColor itemColor() const {
        return mItemColor;
    }

    QColor lineColor() const  {
        return mLineColor;
    }

    void setLineColor(const QColor &color);
    void setTextColor(const QColor &color);
    void setItemColor(const QColor &color);

    void setFont(QFont &font);

protected:
     void mousePressEvent(QGraphicsSceneMouseEvent *event);
     void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
     void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

public slots:
    void setMode(Mode mode);
    void setItemType(DiagramItem::DiagramType type);
    void editorLostFocus(DiagramTextItem *item);

signals:
    void itemInserted(DiagramItem *item);
    void textInserted(QGraphicsTextItem *item);
    void itemSelected(QGraphicsItem *item);

private:
    bool isItemChange(int type);

    DiagramItem::DiagramType mItemType;
    QMenu *mItemMemu;
    Mode mMode;
    bool leftButtonDown;
    QPointF startPoint;
    QGraphicsLineItem *line;
    QFont mFont;
    DiagramTextItem *textItem;

    QColor mTextColor;
    QColor mItemColor;
    QColor mLineColor;
};


#endif // DIAGRAMSCENE_H
