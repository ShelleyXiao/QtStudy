#include "boardlayout.h"



BoradLayout::BoradLayout(QWidget *parent, int margin, int space)
    :QLayout(parent)
{
    setMargin(margin);
    setSpacing(space);
}

BoradLayout::BoradLayout(int spaceing)
{
    setSpacing(spaceing);
}

BoradLayout::~BoradLayout()
{
    QLayoutItem *p;
    while((p = takeAt(0)))
    {
        delete p;
    }
}

void BoradLayout::addItem(QLayoutItem *item)
{
    add(item, West);
}

void BoradLayout::setGeometry(const QRect &rect)
{
    ItemWrapper *center = 0;
    int eastWidth = 0;
    int westWidth = 0;
    int northHeight = 0;
    int southHeight = 0;
    int centerHeight = 0;
    int i = 0;

    QLayout::setGeometry(rect);

    for(i = 0; i < list.size(); i++) {
        ItemWrapper *wrapper = list.at(i);
        QLayoutItem *item = wrapper->item;
        Position position = wrapper->position;

        if(position == North)
        {
            item->setGeometry(QRect(rect.x(), northHeight, rect.width(),
                                    item->sizeHint().height()));
            northHeight += item->geometry().height() + spacing();
        } else if(position == South)
        {
            item->setGeometry(QRect(rect.x(), rect.y(), rect.width(),
                                    item->sizeHint().height()));
            southHeight += item->geometry().height() + spacing();
            item->setGeometry(QRect(rect.x(),
                                    rect.y() + rect.height() - southHeight + spacing(),
                                    item->geometry().width(),
                                    item->geometry().height()));
        }
        else if(position == Center) {
            center = wrapper;
        }
    }

    centerHeight = rect.height() - southHeight - northHeight;

    for(i = 0; i < list.size(); i++)
    {
        ItemWrapper *wrapper = list.at(i);
        QLayoutItem *item = wrapper->item;
        Position position = wrapper->position;
        if(position == West)
        {
            item->setGeometry(QRect(rect.x() + westWidth, northHeight,
                                    item->sizeHint().width(),
                                    centerHeight));
            westWidth += item->geometry().width() + spacing();
        } else if(position == East)
        {
            item->setGeometry(QRect(item->geometry().x(), item->geometry().y(),
                                    item->sizeHint().width(), centerHeight));

            eastWidth += item->geometry().width() + spacing();

            item->setGeometry(QRect(
                                  rect.x() + rect.width() - eastWidth + spacing(),
                                  northHeight, item->geometry().width(),
                                  item->geometry().height()));
        }
    }
    if(center)
    {
        center->item->setGeometry(QRect(westWidth, northHeight,
                                         rect.width() - eastWidth - westWidth,
                                         centerHeight));
    }
}

QLayoutItem *BoradLayout::itemAt(int index) const
{
    ItemWrapper *wrap = list.value(index);
    if(wrap)
    {
        return wrap->item;
    }
    else
    {
        return 0;
    }
}

QLayoutItem *BoradLayout::takeAt(int index)
{
    if(index >= 0 && index < list.size())
    {
        ItemWrapper *i = list.takeAt(index);
        return i->item;
    }

    return 0;
}


int BoradLayout::count() const
{
    return list.size();
}

Qt::Orientations BoradLayout::expandingDirections() const
{
    return Qt::Horizontal | Qt::Vertical;
}

bool BoradLayout::hasHeightForWidth() const
{
    return false;
}

QSize BoradLayout::sizeHint() const
{
    return calculteSize(SizeHint);
}

QSize BoradLayout::minimumSize() const
{
    return calculteSize(MinimumSize);
}

void BoradLayout::addWidget(QWidget *widget, BoradLayout::Position position)
{
    add(new QWidgetItem(widget), position);
}

void BoradLayout::add(QLayoutItem *item, BoradLayout::Position position)
{
    list.append(new ItemWrapper(item, position));
}

QSize BoradLayout::calculteSize(BoradLayout::SizeType type) const
{
    QSize totalSize;
    for(int i = 0; i < list.size(); i++)
    {
        ItemWrapper *wrapper = list.at(i);
        QLayoutItem *item = wrapper->item;
        Position position = wrapper->position;
        QSize itemSize;

        if(type == MinimumSize)
        {
            itemSize = item->minimumSize();
        }
        else
        {
            itemSize = item->sizeHint();
        }

        if(position == North || position == South
                || position == Center)
        {
            totalSize.rheight() += itemSize.height();
        }
        if(position == West || position == East
                || position == Center)
        {
            totalSize.rwidth() += itemSize.width();
        }

    }

    return totalSize;
}
