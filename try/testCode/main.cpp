#include "MainWindow.h"
#include <QApplication>
#include"testqstringList.h"
#include"testProperty.h"
#include<QVariant>
#include<QDebug>
#include<QMetaProperty>
#include<QTextCodec>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#if QT_VERSION >= 0x050000
//        QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf8"));
#else
       // QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf8"));
        QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));
        QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));
#endif
    MainWindow w;
    w.show();
    testqstringList entity;
    entity.writeLocafile();
    return a.exec();
}
