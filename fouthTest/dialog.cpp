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

    //布局管理
    mainLayout->addWidget(fileBtn,0,0);
    mainLayout->addWidget(fileLineEdit,0,1);
    mainLayout->addWidget(colorCho,1,0);
    mainLayout->addWidget(colorFrame,1,1);
    mainLayout->addWidget(inputDia,2,0);
    mainLayout->addWidget(inputLabel,2,1);
    connect(fileBtn,SIGNAL(clicked()),this,SLOT(showFile()));
    connect(colorCho,SIGNAL(clicked()),this,SLOT(showColor()));
    connect(inputDia,SIGNAL(clicked()),this,SLOT(showInput()));
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
        mind->warning(this,"提示","请选择颜色");
}

void Dialog::showInput()
{
    bool ok;
    QString str=QInputDialog::getText(this,tr("标准输入对话框"),tr("请输入姓名"),QLineEdit::Normal,inputLabel->text(),&ok);
    if(ok&&!str.isEmpty())
        inputLabel->setText(str);
}

Dialog::~Dialog()
{
}

