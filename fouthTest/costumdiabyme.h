#ifndef COSTUMDIABYME_H
#define COSTUMDIABYME_H
/*
此文件用于测试自定义对话框
designed by sch
2019.10.13
1.0版：好尴尬，没用上现在，书是骗纸！！！
*/

#include<QDialog>
#include<QPushButton>
#include<QLabel>
#include<QMessageBox>
#include<QGridLayout>

class costumDiaByMe : public QDialog
{
    Q_OBJECT
public:
    costumDiaByMe(QWidget *parent = nullptr);

    ~costumDiaByMe();
private slots:
};

#endif // COSTUMDIABYME_H
