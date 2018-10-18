#include "widget.h"
#include "ui_widget.h"

#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    qDebug() << tr("Perferred按钮")
             << ui->pushButtonPreferred->sizeHint()
             << ui->pushButtonPreferred->minimumSizeHint();

    qDebug() << tr("Expand按钮")
             << ui->pushButtonExpanding->sizeHint()
             << ui->pushButtonExpanding->minimumSizeHint();

    m_pWidget =NULL;
    createWidget();
}

Widget::~Widget()
{
    delete ui;

    if(m_pWidget != NULL) {
        delete m_pWidget;
        m_pWidget = NULL;
    }
}

void Widget::on_pushButtonFixed_clicked()
{
    if(m_pWidget != NULL) {
        m_pWidget->show();
    }
}

void Widget::createWidget()
{
    m_pWidget = new QWidget(this, Qt::Window);
    m_pWidget->resize(480, 360);
    m_pWidget->setWindowTitle(tr("单行编辑器的布局"));
    QVBoxLayout *mainLayout = new QVBoxLayout(m_pWidget);

    QLineEdit *leFixed = new QLineEdit(m_pWidget);
    leFixed->setText(tr("Fixed"));
    QSizePolicy sp = leFixed->sizePolicy();
    sp.setHorizontalPolicy(QSizePolicy::Fixed);
    leFixed->setSizePolicy(sp);

    QLineEdit *lePreferred = new QLineEdit(m_pWidget);
    lePreferred->setText(tr("Preferred"));
    sp = lePreferred->sizePolicy();
    sp.setHorizontalPolicy(QSizePolicy::Preferred);
    lePreferred->setSizePolicy(sp);

    QHBoxLayout *lay1 = new QHBoxLayout();
    lay1->addWidget(leFixed);
    lay1->addWidget(lePreferred);
    mainLayout->addLayout(lay1);


    QLineEdit *lePreferred2 = new QLineEdit(m_pWidget);
    lePreferred2->setText(tr("Preferred2"));
    sp = lePreferred2->sizePolicy();
    sp.setHorizontalPolicy(QSizePolicy::Preferred);
    lePreferred2->setSizePolicy(sp);

    QLineEdit *leMinimum = new QLineEdit(m_pWidget);
    leMinimum->setText(tr("Minimum"));
    sp = leMinimum->sizePolicy();
    sp.setHorizontalPolicy(QSizePolicy::Minimum);
    leMinimum->setSizePolicy(sp);

    QHBoxLayout *lay2 = new QHBoxLayout();
    lay1->addWidget(lePreferred2);
    lay1->addWidget(leMinimum);
    mainLayout->addLayout(lay2);


    QLineEdit *leMinimum2 = new QLineEdit(m_pWidget);
    leMinimum2->setText(tr("Minimum2"));
    sp = leMinimum2->sizePolicy();
    sp.setHorizontalPolicy(QSizePolicy::Minimum);
    leMinimum2->setSizePolicy(sp);

    QLineEdit *leExpanding = new QLineEdit(m_pWidget);
    leExpanding->setText(tr("Expanding"));
    sp = leExpanding->sizePolicy();
    sp.setHorizontalPolicy(QSizePolicy::Expanding);
    leExpanding->setSizePolicy(sp);

    QHBoxLayout *lay3 = new QHBoxLayout();
    lay1->addWidget(leMinimum2);
    lay1->addWidget(leExpanding);
    mainLayout->addLayout(lay3);

    m_pWidget->setLayout(mainLayout);

    qDebug()<<tr("Fixed 编辑器建议尺寸：")<<leFixed->sizeHint();
    qDebug()<<tr("Preferred 编辑器建议尺寸：")<<lePreferred->sizeHint();
    qDebug()<<tr("Preferred 编辑器最小建议尺寸：")<<lePreferred->minimumSizeHint();
    qDebug()<<tr("Minimum 编辑器建议尺寸：")<<leMinimum->sizeHint();
    qDebug()<<tr("Expanding 编辑器建议尺寸：")<<leExpanding->sizeHint();
    qDebug()<<tr("Expanding 编辑器最小建议尺寸：")<<leExpanding->minimumSizeHint();

}
