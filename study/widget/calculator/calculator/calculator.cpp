#include "calculator.h"
#include <cmath>

#include "button.h"
#include <QtWidgets>
#include <QDebug>

Calculator::Calculator(QWidget *parent)
    :QWidget(parent)
{
    sumInMemory = 0.0;
    sumSoFar = 0.0;
    factorSoFar = 0.0;
    waitingForOperand = true;

// ui
    display = new QLineEdit("0");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMaxLength(15);

    QFont font = display->font();
    font.setPointSize(font.pointSize() + 8);
    display->setFont(font);

//buttons
    for(int i = 0; i < NumDigitButtons; i++) {
        digitButtons[i] = createButton(QString::number(i), SLOT(digittClicked()));
    }

    Button *pointButton = createButton(tr("."), SLOT(pointClicked()));
    Button *changeSignButton = createButton(tr("\302\261"), SLOT(changeSignClicked()));
    Button *backspaceButton = createButton(tr("backspace"), SLOT(backspaceClicked()));
    Button *clearButton = createButton(tr("Clear"), SLOT(clear()));

    Button *clearAllButton = createButton(tr("Clear All"), SLOT(clearAll()));

    Button *clearMemoryButton = createButton(tr("MC"), SLOT(clearMemory()));
    Button *readMemoryButton = createButton(tr("MR"), SLOT(readMemory()));
    Button *setMemoryButton = createButton(tr("MS"), SLOT(setMemory()));
    Button *addToMemoryButton = createButton(tr("M+"), SLOT(addToMemory()));

    Button *divisionButton = createButton(tr("\303\267"), SLOT(muliplicativeOperatorClicked()));
    Button *timesButton = createButton(tr("\303\227"), SLOT(muliplicativeOperatorClicked()));
    Button *minusButton = createButton(tr("-"), SLOT(additiveOperatorClicked()));
    Button *plusButton = createButton(tr("+"), SLOT(additiveOperatorClicked()));

    Button *squareRootButton = createButton(tr("Sqrt"), SLOT(unaryOperatorClicked()));
    Button *powerButton = createButton(tr("x\302\262"), SLOT(unaryOperatorClicked()));
    Button *reciprocalButton = createButton(tr("1/x"), SLOT(unaryOperatorClicked()));
    Button *equalButton = createButton(tr("="), SLOT(equalClicked()));

    QGridLayout *mainlayout = new QGridLayout;
    mainlayout->setSizeConstraint(QLayout::SetFixedSize);
    mainlayout->addWidget(display, 0, 0, 1, 6);
    mainlayout->addWidget(backspaceButton, 1, 0, 1, 2);
    mainlayout->addWidget(clearButton, 1, 2, 1, 2);;
    mainlayout->addWidget(clearAllButton, 1, 4, 1, 2);

    mainlayout->addWidget(clearMemoryButton, 2, 0);
    mainlayout->addWidget(readMemoryButton, 3, 0);
    mainlayout->addWidget(setMemoryButton, 4, 0);
    mainlayout->addWidget(addToMemoryButton, 5, 0);

    for(int i = 1; i < NumDigitButtons; i++) {
        int row = ((9 - i) / 3) + 2;
        int colomn = ((i - 1) %3) + 1;
        mainlayout->addWidget(digitButtons[i], row, colomn);
    }

    mainlayout->addWidget(digitButtons[0], 5, 1);
    mainlayout->addWidget(pointButton, 5, 2);
    mainlayout->addWidget(changeSignButton, 5, 3);

    mainlayout->addWidget(divisionButton, 2, 4);
    mainlayout->addWidget(timesButton, 3, 4);
    mainlayout->addWidget(minusButton, 4, 4);
    mainlayout->addWidget(plusButton, 5, 4);

    mainlayout->addWidget(squareRootButton, 2, 5);
    mainlayout->addWidget(powerButton, 3, 5);
    mainlayout->addWidget(reciprocalButton, 4, 5);
    mainlayout->addWidget(equalButton, 5, 5);

    setLayout(mainlayout);
    setWindowTitle(tr("Calculator"));

}

void Calculator::digittClicked()
{
    Button *clickedButton = qobject_cast<Button *>(sender());
    int digitValue = clickedButton->text().toInt();
    if(display->text() == "0" && digitValue == 0.0)
    {
        return;
    }

    qDebug() << "digittClicked";

    if(waitingForOperand)
    {
        qDebug() << "digittClicked waitingForOperand";
        display->clear();
        waitingForOperand = false;
    }
    display->setText(display->text() + QString::number(digitValue));

}

void Calculator::unaryOperatorClicked()
{
    Button *clickedButton = qobject_cast<Button *>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();
    double result = 0.0;

    if(clickedOperator == tr("Sqrt"))
    {
        if(operand < 0.0)
        {
            abortOperator();
            return;
        }
        result = std::sqrt(operand);
    } else if(clickedOperator == tr("x\302\262")) {
        result = std::pow(operand, 2.0);
    } else if(clickedOperator == tr("1/x")) {
        if(operand == 0.0)
        {
            abortOperator();
            return;
        }
        result = 1.0 / operand;
    }
    display->setText(QString::number(result));
    waitingForOperand = true;
}

void Calculator::additiveOperatorClicked()
{
    Button *clickedButton = qobject_cast<Button *>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();

    if(!pendingMultiplicativeOperator.isEmpty())
    {
        if(!calculator(operand, pendingMultiplicativeOperator)) {
            abortOperator();
            return;
        }
        display->setText(QString::number(factorSoFar));
        operand = factorSoFar;
        factorSoFar = 0.0;
        pendingMultiplicativeOperator.clear();
    }

    if(!pendingAdditiveOperator.isEmpty()) {
        if(!calculator(operand, pendingAdditiveOperator)) {
            abortOperator();
            return;
        }
        display->setText(QString::number(sumSoFar));
    } else {
        sumSoFar = operand;
    }

    pendingAdditiveOperator = clickedOperator;
    waitingForOperand = true;

}

void Calculator::muliplicativeOperatorClicked()
{
    Button *clickedButton = qobject_cast<Button *>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();

    qDebug() << "muliplicativeOperatorClicked";

    if(!pendingMultiplicativeOperator.isEmpty())
    {
        if(!calculator(operand, pendingMultiplicativeOperator)) {
            abortOperator();
            return;
        }
        display->setText(QString::number(factorSoFar));

    } else {
        factorSoFar = operand;
    }
    pendingMultiplicativeOperator = clickedOperator;
    waitingForOperand = true;

}

void Calculator::equalClicked()
{
    double operand = display->text().toDouble();
    if(!pendingMultiplicativeOperator.isEmpty())
    {
        if(!calculator(operand, pendingMultiplicativeOperator)) {
            abortOperator();
            return;
        }
        operand = factorSoFar;
        factorSoFar = 0.0;
        pendingMultiplicativeOperator.clear();
    }

    if(!pendingAdditiveOperator.isEmpty()) {
        if(!calculator(operand, pendingAdditiveOperator)) {
            abortOperator();
            return;
        }
        pendingAdditiveOperator.clear();
    } else {
        sumSoFar = operand;
    }
    display->setText(QString::number(sumSoFar));
    sumSoFar = 0.0;
    waitingForOperand = true;
}

void Calculator::pointClicked()
{
    if(waitingForOperand)
    {
        display->setText("0");
    }
    if(!display->text().contains('.'))
    {
        display->setText(display->text() + tr("."));
    }
    waitingForOperand = false;
}

void Calculator::changeSignClicked()
{
    QString text = display->text();
    double value = text.toDouble();

    if(value > 0.0)
    {
        text.prepend("-");
    } else if(value < 0.0) {
        text.remove(0, 1);
    }
    display->setText(text);
}

void Calculator::backspaceClicked()
{
    if(waitingForOperand)
    {
        return;
    }
    QString text = display->text();
    text.chop(1);
    if(text.isEmpty())
    {
        text="0";
        waitingForOperand = true;
    }
    display->setText(text);
}

void Calculator::clear()
{
    if(waitingForOperand)
    {
        return;
    }
    display->setText("0");
    waitingForOperand = true;
}

void Calculator::clearAll()
{
    sumSoFar = 0.0;
    factorSoFar = 0.0;
    pendingAdditiveOperator.clear();
    pendingAdditiveOperator.clear();
    display->setText("0");
    waitingForOperand = true;
}

void Calculator::clearMemory()
{
    sumInMemory = 0.0;
}

void Calculator::readMemory()
{
    display->setText(QString::number(sumInMemory));
    waitingForOperand = true;
}

void Calculator::setMemory()
{
    equalClicked();
    sumInMemory += display->text().toDouble();
}

void Calculator::addToMemory()
{
    equalClicked();
    sumInMemory +=display->text().toDouble();
}

Button *Calculator::createButton(const QString &text, const char *member)
{
    Button *button = new Button(text);
    connect(button, SIGNAL(clicked(bool)), this, member);
    return button;
}

void Calculator::abortOperator()
{
    clearAll();
    display->setText(tr("####"));
}

bool Calculator::calculator(double rightOperand, const QString &pendingOperator)
{
    if(pendingOperator == tr("+")) {
        sumSoFar += rightOperand;
    } else if(pendingOperator == tr("-")) {
        sumSoFar -= rightOperand;
    } else if(pendingOperator == tr("\303\227"))  {
        factorSoFar *= rightOperand;
    } else if(pendingOperator == tr("\303\267")) {
        if(rightOperand == 0.0)
            return false;
        factorSoFar /= rightOperand;
    }

    return true;
}
