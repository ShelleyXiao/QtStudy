#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>

QT_BEGIN_NAMESPACE

class QLineEdit;

QT_END_NAMESPACE

class Button;

class Calculator : public QWidget {
    Q_OBJECT
public:
    Calculator(QWidget *parent = 0);

private slots:
    void digittClicked();
    void unaryOperatorClicked();
    void additiveOperatorClicked();
    void muliplicativeOperatorClicked();
    void equalClicked();
    void pointClicked();
    void changeSignClicked();
    void backspaceClicked();
    void clear();
    void clearAll();
    void clearMemory();
    void readMemory();
    void setMemory();
    void addToMemory();


private  :
    QLineEdit *display;

    enum {NumDigitButtons = 10};
    Button *digitButtons[NumDigitButtons];

    double sumInMemory;
    double sumSoFar;
    double factorSoFar;
    QString pendingAdditiveOperator;
    QString pendingMultiplicativeOperator;
    bool waitingForOperand;

    Button *createButton(const QString &text, const char* member);
    void abortOperator();
    bool calculator(double rightOperand, const QString &pendingOperator);
};


#endif // CALCULATOR_H
