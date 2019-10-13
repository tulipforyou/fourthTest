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

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}


