#include "MainWindow.h"
#include <QApplication>
#include"testPtr.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    ns_testPrt::testPtr item;
    item.test_shared_ptr();
    return a.exec();
}
