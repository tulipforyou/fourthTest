/*
QT normal dialog box test
Designed by sch
time:2019.10.13
*/

/*
standard normal box:
    QFileDialog         :standard file dialog box
    QColorDialog        :standard color dialog box
    QFontDialog         :standard font dialog box
    QInputDialog        :standard input dialog box
    QMessageDialog      :standard message dialog box
*/
#include "dialog.h"
#include "costumdiabyme.h"
#include "toolbox.h"

#include <QApplication>
#include<QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w0;
    toolBox t0;


    w0.show();
    //t0.show();
    return a.exec();
}


