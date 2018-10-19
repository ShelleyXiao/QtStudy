#include "onebox.h"
#include <QPainter>


OneBox::OneBox(const QColor &color)
    :brushColor(color)
{

}

QRectF OneBox::boundingRect() const
{
    qreal penWidth = 1;

    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2,
                  20 + penWidth, 20 + penWidth);
}

void OneBox::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-10, -10, 20, 20, QPixmap(":/images/box.gif"));
    painter->setBrush(brushColor);
    QColor color = brushColor;
    color.setAlpha(20);;
    painter->setPen(color);
    painter->drawRect(-10, -10, 20, 20);
}

QPainterPath OneBox::shape() const
{
    QPainterPath path;
    path.addRect(-9.5, -9.5, 19, 19);
    return path;
}
