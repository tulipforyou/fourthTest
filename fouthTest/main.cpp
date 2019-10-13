/*
QT normal dialog box test
Designed by sch
time:2019.10.13
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
