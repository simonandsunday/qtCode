#include "MainWindow.h"
#include <QApplication>
#include"testToolBox.h"
#include"teststyle.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    testToolBox w;
    w.show();
    return a.exec();
}
