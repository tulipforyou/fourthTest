#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("Different dialog example"));
    mainLayout=new QGridLayout(this);

    fileBtn=new QPushButton(tr("点击打开文件"));
    fileBtn->setMinimumWidth(100);
    fileBtn->setMinimumHeight(20);
    fileBtn->setMaximumWidth(100);
    fileBtn->setMaximumHeight(20);
    fileLineEdit=new QLineEdit;
    fileLineEdit->setMinimumWidth(500);
    fileLineEdit->setMinimumHeight(20);
    fileLineEdit->setMaximumWidth(1000);
    fileLineEdit->setMaximumHeight(40);
    colorCho=new QPushButton(tr("点击选择颜色"));
    colorCho->setMinimumWidth(100);
    colorCho->setMinimumHeight(20);
    colorCho->setMaximumWidth(100);
    colorCho->setMaximumHeight(20);
    colorFrame=new QFrame;
    mind=new QMessageBox(this);
    colorFrame->setFrameShape(QFrame::Box);
    colorFrame->setAutoFillBackground(true);
    inputDia=new QPushButton(tr("点击修改名字"));
    inputDia->setMinimumWidth(100);
    inputDia->setMinimumHeight(20);
    inputDia->setMaximumWidth(100);
    inputDia->setMaximumHeight(20);
    inputLabel=new QLabel();
    inputLabel->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    costumBtn=new QPushButton(tr("点击显示自定义对话框"));
    costumBtn->setMinimumWidth(180);
    costumBtn->setMinimumHeight(20);
    costumBtn->setMaximumWidth(180);
    costumBtn->setMaximumHeight(20);
    costumLabel=new QLabel(tr("自定义对话框测试"));
    costumLabel->setFrameStyle(QFrame::Panel|QFrame::Sunken);

    //布局管理
    mainLayout->addWidget(fileBtn,0,0);
    mainLayout->addWidget(fileLineEdit,0,1);
    mainLayout->addWidget(colorCho,1,0);
    mainLayout->addWidget(colorFrame,1,1);
    mainLayout->addWidget(inputDia,2,0);
    mainLayout->addWidget(inputLabel,2,1);
    mainLayout->addWidget(costumBtn,3,0);
    mainLayout->addWidget(costumLabel,3,1);
    connect(fileBtn,SIGNAL(clicked()),this,SLOT(showFile()));
    connect(colorCho,SIGNAL(clicked()),this,SLOT(showColor()));
    connect(inputDia,SIGNAL(clicked()),this,SLOT(showInput()));
    connect(costumBtn,SIGNAL(clicked()),this,SLOT(showCostumDia()));
}

void Dialog::showFile()
{
    QString str=QFileDialog::getOpenFileName(this,"open file dialog","/home/sunchaohui","C++files(*.cpp)::C files(*.c)::Header files(*.h)");
    fileLineEdit->setText(str);
}

void Dialog::showColor()
{
    QColor clo=QColorDialog::getColor(Qt::blue);
    if(clo.isValid())//判断有颜色被选择
        colorFrame->setPalette(QPalette(clo));
    else
        switch(mind->warning(this,"提示","请选择颜色",QMessageBox::Cancel|QMessageBox::Ok,QMessageBox::Cancel))
        {
        case QMessageBox::Cancel:exit(0);
        case QMessageBox::Ok:
            showColor();
            break;
        }
}

void Dialog::showInput()
{
    bool ok;
    //标准TEXT对话框，对应的还有getInt,getDouble等标准输入对话框
    QString str=QInputDialog::getText(this,tr("标准输入对话框"),tr("请输入姓名"),QLineEdit::Normal,inputLabel->text(),&ok);
    if(ok&&!str.isEmpty())
        inputLabel->setText(str);
}

void Dialog::showCostumDia()
{
    QMessageBox costumMessBox;
    costumMessBox.setWindowTitle(tr("自定义对话框"));
    QPushButton *yesBtn=costumMessBox.addButton(tr("Yes"),QMessageBox::ActionRole);
    QPushButton *noBtn=costumMessBox.addButton(tr("No"),QMessageBox::ActionRole);
    QPushButton *cancelBtn=costumMessBox.addButton(QMessageBox::Cancel);
    costumMessBox.setText(tr("这是一个自定义对话框哦"));
    costumMessBox.exec();//显示此对话框
    if(costumMessBox.clickedButton()==yesBtn)
        costumLabel->setText(tr("点击了是"));
    if(costumMessBox.clickedButton()==noBtn)
        costumLabel->setText(tr("点击了否"));
    if(costumMessBox.clickedButton()==cancelBtn)
        costumLabel->setText(tr("点击了取消"));
}

Dialog::~Dialog()
{
}

