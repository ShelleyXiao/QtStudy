#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsTextItem>
#include <QTextDocument>
#include <QGraphicsEllipseItem>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    QGraphicsScene *scene = new QGraphicsScene;


    scene->setSceneRect(0, 0, 600, 400);

    QGraphicsSimpleTextItem *sItem = new QGraphicsSimpleTextItem;
    sItem->setBrush(QBrush(QColor(0, 160, 200)));
    sItem->setText(QString::fromLocal8Bit("简单的"));

    QFont font = sItem->font();
    font.setPixelSize(40);
    font.setItalic(true);;
    font.setUnderline(true);
    sItem->setFont(font);
//    sItem->setPos(60, 60);
    scene->addItem(sItem);

    QGraphicsTextItem *nItem = new QGraphicsTextItem;
//    nItem->setPlainText(QString::fromLocal8Bit("简单的"));
    QString strHTML = QString("<html> \ <head> \ <style> \
                                   font{color:white;} #f{font-size:18px; color: #00A0E6;} \
                                   </style> \ </head> \ <body>\ <font>%1</font><font id=\"f\">%2</font> \ "
                                                                                         "<br/><br/> \ <img src=\":/Images/logo\" width=\"100\" height=\"100\"> \ </body> \ </html>").arg("I am a ").arg("Qter");
//    nItem->setPlainText(strHTML);
    nItem->setDefaultTextColor(QColor(168, 168, 168));
    nItem->setPos(0, 60);

    nItem->setTextInteractionFlags(Qt::TextEditorInteraction);
//    connect(nItem->document(), &QTextDocument::contentsChanged, [=]() {
//        qDebug() << pItem->toPlainText();
//    });

    font = nItem->font();
    font.setPixelSize(20);
    font.setItalic(true);
    font.setBold(true);
    nItem->setFont(font);

    scene->addItem(nItem);

    QGraphicsLineItem *lItem = new QGraphicsLineItem;
    QPen pen = lItem->pen();
    pen.setColor(QColor(9, 120, 180));
    pen.setWidth(5);
    lItem->setPen(pen);

    lItem->setLine(QLineF(80, 80, 200, 100));

    scene->addItem(lItem);

    QGraphicsRectItem *rItem = new QGraphicsRectItem;

    pen = rItem->pen();
    pen.setWidth(5);
    pen.setColor(Qt::white);
    rItem->setPen(pen);
    rItem->setBrush(QBrush(QColor(0, 160, 230)));
    rItem->setRect(QRectF(50, 50, 200, 200));
    scene->addItem(rItem);

    QGraphicsEllipseItem* eItem = new QGraphicsEllipseItem;
    pen = eItem->pen();
    pen.setWidth(5);
    pen.setColor(Qt::white);
    eItem->setPen(pen);
    eItem->setBrush(QBrush(QColor(0, 160, 230)));

    eItem->setRect(QRectF(100, 100, 200, 100));
    eItem->setStartAngle(16 * 90);
    eItem->setSpanAngle(16 * 270);
    scene->addItem(eItem);

    const float pi = 3.1415926f;
    QGraphicsPathItem *pItem = new QGraphicsPathItem;
    pItem->setPos(100, 300);
    QPainterPath startPath;
    startPath.moveTo(90, 50);
    for(int i = 0; i < 5; i++) {
        startPath.lineTo(50 + 40 * std::cos(0.8 * i * pi), 50 + 40 * std::sin(0.8 * i * pi));
    }
    startPath.closeSubpath();
    pItem->setPath(startPath);
    pen = pItem->pen();
    pen.setWidth(5);
    pen.setColor(Qt::white);
    pItem->setPen(pen);
    pItem->setBrush(QBrush(QColor(0, 160, 230)));
    scene->addItem(pItem);


    QGraphicsView* view = new QGraphicsView(scene);
    view->show();
    view->setStyleSheet("border:none; background:transparent;");

    return a.exec();
}
