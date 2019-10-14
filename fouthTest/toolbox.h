#ifndef TOOLBOX_H
#define TOOLBOX_H

#include<QToolBox>
#include<QToolButton>
#include<QGroupBox>
#include<QVBoxLayout>

class toolBox : public QToolBox
{
    Q_OBJECT

public:
    toolBox(QWidget *parent = nullptr);


private:
    QToolButton *button1;
    QToolButton *button2;


private slots:

};

#endif // TOOLBOX_H
