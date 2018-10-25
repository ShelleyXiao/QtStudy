#ifndef CONSOLE_H
#define CONSOLE_H

#include <QPlainTextEdit>


class Console : public QPlainTextEdit
{
    Q_OBJECT

signals:
    void getData(const QByteArray &data);

public:
    explicit Console(QWidget *parent  = nullptr);

    void putData(const QByteArray &data);
    void setLocaleEchoEnabled(bool set);

protected:
    void keyPressEvent(QKeyEvent *event)   Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseDoubleClickEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void contextMenuEvent(QContextMenuEvent *event) Q_DECL_OVERRIDE;


private:
    bool localEchoEnabled;
};

#endif // CONSOLE_H
