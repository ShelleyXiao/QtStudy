#include "console.h"

#include <QScrollBar>
#include <QtCore/QDebug>

Console::Console(QWidget *parent )
    : QPlainTextEdit(parent),
      localEchoEnabled(false)
{
    document()->setMaximumBlockCount(100);
    QPalette p = palette();
    p.setColor(QPalette::Base, Qt::black);
    p.setColor(QPalette::Text, Qt::red);
    setPalette(p);
}

void Console::putData(const QByteArray &data)
{
    insertPlainText(QString(data));
    QScrollBar *bar = verticalScrollBar();
    bar->setValue(bar->maximum());
}

void Console::setLocaleEchoEnabled(bool set)
{
    localEchoEnabled = set;
}

void Console::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()) {
    case Qt::Key_Backspace:
    case Qt::Key_Left:
    case Qt::Key_Right:
    case Qt::Key_Down:
        break;
    default:
        if(localEchoEnabled) {
            emit getData(event->text().toLocal8Bit());
        }
        break;
    }
}

void Console::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    setFocus();
}

void Console::mouseDoubleClickEvent(QMouseEvent *event)
{
     Q_UNUSED(event);
}

void Console::contextMenuEvent(QContextMenuEvent *event)
{
    Q_UNUSED(event);
}
