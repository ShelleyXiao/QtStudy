#include "dialog.h"
#include "ui_dialog.h"

#include <QDialog>
#include <QtWidgets>




Dialog::Dialog(QWidget *parent) :
    QDialog(parent)
{
    createRotableGroupBox();
    createOptionsGroupBox();
    createButtonBox();

    mainLayout = new QGridLayout;
    mainLayout->addWidget(rotableGroupBox, 0, 0);
    mainLayout->addWidget(optionGroupBox, 1, 0);
    mainLayout->addWidget(buttonBox, 2, 0);

    mainLayout->setSizeConstraint(QLayout::SetMinimumSize);

    setLayout(mainLayout);
    setWindowTitle("Dynamic layout");
}

Dialog::~Dialog()
{

}

void Dialog::buttonsOrientionChanged(int index)
{
     mainLayout->setSizeConstraint(QLayout::SetMinimumSize);
     setMinimumSize(0, 0);

     Qt::Orientation orientation = Qt::Orientation(buttonsOrientionComboBox->itemData(index).toInt());
    if(orientation == buttonBox->orientation())
    {
        return;
    }
    mainLayout->removeWidget(buttonBox);
    int spaceing = mainLayout->spacing();

    QSize oldSizeHint = buttonBox->sizeHint() + QSize(spaceing, spaceing);
    buttonBox->setOrientation(orientation);
    QSize newSizeHint = buttonBox->sizeHint() + QSize(spaceing, spaceing);

    if(orientation == Qt::Horizontal)
    {
        mainLayout->addWidget(buttonBox, 2, 0);
        resize(size() + QSize(-oldSizeHint.width(), newSizeHint.height()));
    }
    else
    {
        mainLayout->addWidget(buttonBox, 0, 3, 2, 1);
        resize(size() + QSize(newSizeHint.width(), -oldSizeHint.height()));
    }

    mainLayout->setSizeConstraint(QLayout::SetDefaultConstraint);

}

void Dialog::roateWidgets()
{
    Q_ASSERT(rotableWidgets.count() % 2 == 0);
    foreach(QWidget *widget , rotableWidgets)
    {
        rotableLayout->removeWidget(widget);
    }

    rotableWidgets.enqueue(rotableWidgets.dequeue());

    const int n = rotableWidgets.count();
    for(int i = 0; i < n / 2 ; i++)
    {
        rotableLayout->addWidget(rotableWidgets[n - i - 1], 0, i);
        rotableLayout->addWidget(rotableWidgets[i], 1, i);

    }
}

void Dialog::help()
{
    QMessageBox::information(this, tr("Dynamic Layouts Help"),
                               tr("This example shows how to change layouts "
                                  "dynamically."));
}

void Dialog::createRotableGroupBox()
{
    rotableGroupBox = new QGroupBox(tr("rotable widgets"));
    rotableWidgets.enqueue(new QSpinBox);
    rotableWidgets.enqueue(new QSlider);
    rotableWidgets.enqueue(new QDial);
    rotableWidgets.enqueue(new QProgressBar);

    int n = rotableWidgets.count();

    for(int i = 0; i < rotableWidgets.size(); i++)
    {
        connect(rotableWidgets[i], SIGNAL(valueChanged(int)),
                rotableWidgets[(i + 1 )%n], SLOT(setValue(int)));
    }

    rotableLayout = new QGridLayout;
    rotableGroupBox->setLayout(rotableLayout);
    roateWidgets();
}

void Dialog::createOptionsGroupBox()
{
    optionGroupBox = new QGroupBox(tr("Options"));

    buttonsOrientionLabel = new QLabel(tr("oriention of buttons: "));
    buttonsOrientionComboBox = new QComboBox;
    buttonsOrientionComboBox->addItem(tr("Horizontal"), Qt::Horizontal);
    buttonsOrientionComboBox->addItem(tr("Vertical"), Qt::Vertical);

    connect(buttonsOrientionComboBox, SIGNAL(currentIndexChanged(int)),
                                             this, SLOT(buttonsOrientionChanged(int)));

    optionsLayout = new QGridLayout;
    optionsLayout->addWidget(buttonsOrientionLabel, 0, 0);
    optionsLayout->addWidget(buttonsOrientionComboBox, 0, 1);
    optionsLayout->setColumnStretch(2, 1);

    optionGroupBox->setLayout(optionsLayout);
}

void Dialog::createButtonBox()
{
    buttonBox = new QDialogButtonBox;

    closeButton = buttonBox->addButton(QDialogButtonBox::Close);
    helpButton = buttonBox->addButton(QDialogButtonBox::Help);
    rotableWidgetsButton = buttonBox->addButton(tr("rotate &widget"),
                                                QDialogButtonBox::ActionRole);

    connect(closeButton, SIGNAL(clicked(bool)), this,
            SLOT(close()));
    connect(helpButton, SIGNAL(clicked(bool)), this,
            SLOT(help()));
    connect(rotableWidgetsButton, SIGNAL(clicked(bool)),
            this, SLOT(roateWidgets()));
}
