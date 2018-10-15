#ifndef DIALOG_H
#define DIALOG_H

#include <QtWidgets>

#include <QDialog>

QT_BEGIN_NAMESPACE

class QAction;
class QDialogButtonBox;
class QGroupBox;
class QLable;
class QLineEdit;
class QTextBrowser;
class QMenu;
class QPushButton;
class QTextEdit;
class QMenuBar;

QT_END_NAMESPACE

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:

    enum {NumGridRows = 3, NumButtons = 4};

    Ui::Dialog *ui;

    QMenuBar *menuBar;
    QGroupBox *horizontalGroupbox;
    QGroupBox *gridGroupbox;
    QGroupBox *formGroupbox;

    QTextEdit *smallEdit;
    QTextEdit *bigEdit;

    QLabel *labels[NumGridRows];
    QLineEdit *lineEdits[NumGridRows];

    QPushButton *buttons[NumButtons];
    QDialogButtonBox *buttonBox;

    QMenu *fileMenu;
    QAction *exitAciton;



private:
    void createMenu();
    void createHorizontalGroupBox();
    void createGridGroupBox();
    void createFormGroupBox();
};

#endif // DIALOG_H
