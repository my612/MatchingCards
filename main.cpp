//#include "mainwindow.h"
#include "playing.h"
#include "loginwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //    MainWindow w;
    //    w.show();
    LoginWindow L1;
    L1.show();
    //Playing p;
    return a.exec();
}
