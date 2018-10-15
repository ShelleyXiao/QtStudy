#include "dialog.h"
#include "ui_dialog.h"

#include <QtWidgets>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent)
{
//    ui->setupUi(this);
    createMenu();
    createHorizontalGroupBox();
    createGridGroupBox();
    createFormGroupBox();

    bigEdit = new QTextEdit;
    bigEdit->setPlainText(tr("The widget takes up all remaining"));
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMenuBar(menuBar);
    layout->addWidget(horizontalGroupbox);
    layout->addWidget(gridGroupbox);
    layout->addWidget(formGroupbox);
    layout->addWidget(bigEdit);
    layout->addWidget(buttonBox);

    setLayout(layout);

    setWindowTitle(tr("baisc layout"));

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::createMenu()
{
    menuBar = new QMenuBar;
    fileMenu = new QMenu(tr("&File"), this);
    menuBar->addMenu(fileMenu);
    exitAciton = fileMenu->addAction(tr("&Exit"));

    connect(exitAciton, SIGNAL(triggered()), this,
            SLOT(accept()));
}

void Dialog::createHorizontalGroupBox()
{
    horizontalGroupbox = new QGroupBox(tr("Horizontal layout"));
    QHBoxLayout *layout = new QHBoxLayout;
    for(int i = 0; i < NumButtons; i++)
    {
        buttons[i] = new QPushButton(tr("button %1").arg(i + 1));
        layout->addWidget(buttons[i]);
    }
    horizontalGroupbox->setLayout(layout);
}

void Dialog::createGridGroupBox()
{
    gridGroupbox = new QGroupBox(tr("Grid layout"));
    QGridLayout *layout = new QGridLayout;
    for(int i = 0; i < NumGridRows; i++)
    {
        labels[i] = new QLabel(tr("Line %1").arg(i + 1));
        lineEdits[i] = new QLineEdit;
        layout->addWidget(labels[i], i + 1, 0);
        layout->addWidget(lineEdits[i], i + 1 , 1);

    }

    smallEdit = new QTextEdit;
    smallEdit->setText(tr("This widget takes up about two thrids"));
    layout->addWidget(smallEdit, 0, 2, 4, 1);

    layout->setColumnStretch(1, 10);
    layout->setColumnStretch(2, 20);
    gridGroupbox->setLayout(layout);
}

void Dialog::createFormGroupBox()
{
    formGroupbox = new QGroupBox(tr("From layout"));
    QFormLayout *layout = new QFormLayout;
    layout->addRow(new QLabel(tr("Line 1: ")), new QLineEdit);
    layout->addRow(new QLabel(tr("Line 2: ")), new QComboBox);
    layout->addRow(new QLabel(tr("Line 3: ")), new QSpinBox);
    formGroupbox->setLayout(layout);
}
