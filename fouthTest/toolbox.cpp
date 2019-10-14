#include "toolbox.h"

toolBox::toolBox(QWidget *parent)
    :QToolBox(parent)
{
    setWindowTitle(tr("QToolBox测试"));
    button1=new QToolButton;
    button1->setText(tr("孙朝辉"));
    button2=new QToolButton;
    button2->setText(tr("王冰琦"));
    QGroupBox * group1=new QGroupBox;
    QVBoxLayout *layout1=new QVBoxLayout(group1);
    layout1->setAlignment(Qt::AlignCenter);
    layout1->setMargin(15);
    layout1->addWidget(button1);

    layout1->addStretch();//占位符,可防止button拉伸变形

    QGroupBox * group2=new QGroupBox;
    QVBoxLayout *layout2=new QVBoxLayout(group2);
    layout2->setAlignment(Qt::AlignCenter);
    layout2->setMargin(15);
    layout2->addWidget(button2);

    this->addItem(group1,tr("男"));
    this->addItem(group2,tr("女"));
    this->setGeometry(500,500,200,200);
}
