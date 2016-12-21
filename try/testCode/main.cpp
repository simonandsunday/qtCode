#include "MainWindow.h"
#include <QApplication>
#include"testqstringList.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    testqstringList entity;
    entity.readfile();
    return a.exec();
}
