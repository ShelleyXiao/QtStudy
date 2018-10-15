#ifndef BOARDLAYOUT_H
#define BOARDLAYOUT_H

#include <QLayout>

class BoradLayout : public QLayout
{
public :
    enum Position {
        West,
        North,
        South,
        East,
        Center
    };

    explicit BoradLayout(QWidget *parent, int margin = 0, int space = 0);
    BoradLayout(int spaceing = -1);
    ~BoradLayout();


    void addItem(QLayoutItem *)override;
    void setGeometry(const QRect&) Q_DECL_OVERRIDE;
    QLayoutItem *itemAt(int index) const override;
    QLayoutItem *takeAt(int index) override;
    int count() const override;

    Qt::Orientations expandingDirections() const override;
    bool hasHeightForWidth() const override;

    QSize sizeHint() const override;
    QSize minimumSize() const override;


    void addWidget(QWidget *widget, Position position);
    void add(QLayoutItem *item, Position position);

private:
    struct ItemWrapper {
        ItemWrapper(QLayoutItem *i, Position p) {
            item = i;
            position = p;
        }

        QLayoutItem *item;
        Position position;
    };


    enum SizeType {MinimumSize, SizeHint};

    QSize calculteSize(SizeType type) const;

    QList<ItemWrapper *> list;
};

#endif // BOARDLAYOUT_H


