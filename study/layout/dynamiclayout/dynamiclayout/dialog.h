#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QQueue>

namespace Ui {
class Dialog;
}


QT_BEGIN_NAMESPACE
class QComboBox;
class QDialogButtonBox;
class QGridLayout;
class QGroupBox;
class QLabel;
class QPushButton;
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
private slots:
    void buttonsOrientionChanged(int index);
    void roateWidgets();
    void help();



private:
    void createRotableGroupBox();
    void createOptionsGroupBox();
    void createButtonBox();

    QGroupBox *rotableGroupBox;
    QQueue<QWidget *>rotableWidgets;

    QGroupBox *optionGroupBox;
    QLabel *buttonsOrientionLabel;
    QComboBox *buttonsOrientionComboBox;

    QDialogButtonBox *buttonBox;
    QPushButton *closeButton;
    QPushButton *helpButton;
    QPushButton *rotableWidgetsButton;

    QGridLayout *mainLayout;
    QGridLayout *rotableLayout;
    QGridLayout *optionsLayout;

};

#endif // DIALOG_H
