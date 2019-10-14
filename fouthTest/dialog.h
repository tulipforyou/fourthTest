#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QFrame>
#include<QLabel>
#include<QFileDialog>
#include<QPushButton>
#include<QLineEdit>
#include<QGridLayout>
#include<QColorDialog>
#include<QFontDialog>
#include<QInputDialog>
#include<QMessageBox>
#include<QProgressBar>
#include<QComboBox>
#include<QProgressDialog>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);

    //文件对话框
    QPushButton *fileBtn;
    QLineEdit *fileLineEdit;
    QGridLayout *mainLayout;
    //颜色选择对话框
    QPushButton *colorCho;
    QFrame *colorFrame;
    QMessageBox *mind;
    //标准输入对话框
    QPushButton *inputDia;
    QLabel *inputLabel;
    //自定义对话框
    QPushButton *costumBtn;
    QLabel *costumLabel;
    //进度条
    QLabel *fileNum;
    QLineEdit *fileNumLineEdit;
    QLabel *progressType;
    QComboBox *comboBox;
    QProgressBar *progressBar;
    QPushButton *startBtn;

    ~Dialog();

private slots:
    void showFile();
    void showColor();
    void showInput();
    void showCostumDia();
    void startProgress();

private:

};
#endif // DIALOG_H
