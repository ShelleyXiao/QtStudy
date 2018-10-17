#include "diagramscene.h"
#include "arrow.h"

#include <QTextCursor>
#include <QGraphicsSceneMouseEvent>
#include <QTextCursor>

#include <QDebug>

DiagramScene::DiagramScene(QMenu *itemMenu, QObject *parent)
    :QGraphicsScene(parent)
{
    mItemType = DiagramItem::Step;;
    mItemMemu = itemMenu;
    mMode = MoveItem;
    line = 0;
    textItem = 0;

    mTextColor = Qt::black;
    mItemColor = Qt::white;
    mLineColor = Qt::black;
}

void DiagramScene::setLineColor(const QColor &color)
{
    qDebug() << "line color "<< color;
    mLineColor = color;
    if(isItemChange(Arrow::Type)) {
        Arrow *arrow = qgraphicsitem_cast<Arrow *>(selectedItems().first());
        arrow->setColor(mLineColor);
        update();
    }
}

void DiagramScene::setTextColor(const QColor &color)
{
    mTextColor = color;
    if(isItemChange(DiagramTextItem::Type)) {
        DiagramTextItem *text = qgraphicsitem_cast<DiagramTextItem *>(selectedItems().first());
        text->setDefaultTextColor(mTextColor);
        update();
    }
}

void DiagramScene::setItemColor(const QColor &color)
{
    mItemColor = color;
    if(isItemChange(DiagramItem::Type)) {
        DiagramItem *item = qgraphicsitem_cast<DiagramItem *>(selectedItems().first());
        item->setBrush(mItemColor);
        update();
    }
}

void DiagramScene::setFont(QFont &font)
{
    mFont = font;
    if(isItemChange(DiagramTextItem::Type)) {
        DiagramTextItem *text = qgraphicsitem_cast<DiagramTextItem *>(selectedItems().first());
        if(text) {
            text->setFont(mFont);
        }
    }
}

void DiagramScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() != Qt::LeftButton) {
        return;
    }

    DiagramItem *item;
    switch (mMode) {
    case InsertItem:
        item = new DiagramItem(mItemType, mItemMemu);
        qDebug() << "mousePressEvent" << item;
        item->setBrush(mItemColor);
        addItem(item);
        item->setPos(event->scenePos());
        emit itemInserted(item);
        break;
    case InsertText:
        textItem = new DiagramTextItem();
        textItem->setFont(mFont);
        textItem->setTextInteractionFlags(Qt::TextEditorInteraction);
        textItem->setZValue(1000.0);
        connect(textItem, SIGNAL(lostFocus(DiagramTextItem*)),
                this, SLOT(editorLostFocus(DiagramTextItem*)));
        connect(textItem, SIGNAL(selectedChange(QGraphicsItem*)),
                this, SIGNAL(itemSelected(QGraphicsItem *)));
        addItem(textItem);
        textItem->setDefaultTextColor(mTextColor);
        textItem->setPos(event->scenePos());
        emit textInserted(textItem);
        break;
    case InsertLine:
         line = new QGraphicsLineItem(QLineF(event->scenePos(), event->scenePos()));
         line->setPen(QPen(mLineColor, 2));
         addItem(line);
        break;
    default:
        break;
    }
    QGraphicsScene::mousePressEvent(event);
}

void DiagramScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(mMode == InsertLine && line != 0) {
        QLineF newLine(line->line().p1(), event->scenePos());
        line->setLine(newLine);
    } else {
        QGraphicsScene::mouseMoveEvent(event);
    }
}

void DiagramScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(line != 0 && mMode == InsertLine) {
        QList<QGraphicsItem *> startItems = items(line->line().p1());
        if(startItems.count() && startItems.first() == line) {
            startItems.removeFirst();
        }
        QList<QGraphicsItem *> endItems = items(line->line().p2());
        if(endItems.count() && endItems.first() == line) {
            endItems.removeFirst();
        }

        removeItem(line);
        delete line;

        if(startItems.count() > 0 && endItems.count() > 0 &&
                startItems.first()->type() == DiagramItem::Type &&
                endItems.first()->type() == DiagramItem::Type &&
                startItems.first() != endItems.first()) {
            DiagramItem *startItem = qgraphicsitem_cast<DiagramItem *>(startItems.first());
            DiagramItem *endItem = qgraphicsitem_cast<DiagramItem *>(endItems.first());
            Arrow *arrow = new Arrow(startItem, endItem);
            arrow->setColor(mLineColor);
            startItem->addArrow(arrow);
            endItem->addArrow(arrow);
            arrow->setZValue(-1000.0);
            addItem(arrow);
            arrow->updatePosition();

        }
    }
    line = 0;
    QGraphicsScene::mouseReleaseEvent(event);
}

void DiagramScene::setMode(DiagramScene::Mode mode)
{
    qDebug() << "scene mode = " << mode;
    mMode = mode;
}

void DiagramScene::setItemType(DiagramItem::DiagramType type)
{
    mItemType = type;
}

void DiagramScene::editorLostFocus(DiagramTextItem *item)
{
    QTextCursor cursor = item->textCursor();
    cursor.clearSelection();
    item->setTextCursor(cursor);

    if(item->toPlainText().isEmpty()) {
        removeItem(item);
        item->deleteLater();
    }
}

bool DiagramScene::isItemChange(int type)
{
    foreach(QGraphicsItem *item , selectedItems()) {
        if(item->type() == type) {
            qDebug() << "type = " << type;
            return true;
        }
    }
    return false;
}
