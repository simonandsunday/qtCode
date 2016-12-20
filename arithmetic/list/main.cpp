#include "MainWindow.h"
#include <QApplication>
#include"list.h"
#include<QDebug>
#include<QtDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    ns_list::testList entity;
    return a.exec();
}
