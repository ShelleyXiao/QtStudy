#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

#include <QWidget>

class AnalogClock : public QWidget
{
public :
    explicit AnalogClock(QWidget * parent = 0);
    ~AnalogClock();

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // ANALOGCLOCK_H
