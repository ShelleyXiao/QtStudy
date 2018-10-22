#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include "masterthread.h"

class QLabel;
class QLineEdit;
class QSpinBox;
class QPushButton;
class QComboBox;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void transaction();
    void showResponse(const QString &s);
    void processError(const QString &s);
    void processTimeout(const QString &s);

private:
    void setControlsEnable(bool enable);

private:
    int transactionCount;
    QLabel *serialPortLabel;
    QComboBox *serialPortComboBox;
    QLabel *waitResponseLabel;
    QSpinBox *waitResponseSpinBox;
    QLabel *requestLabel;
    QLineEdit *requestLineEdit;
    QLabel *trafficalLable;
    QLabel *statusLabel;
    QPushButton *runButton;

    MasterThread thread;

};

#endif // DIALOG_H
