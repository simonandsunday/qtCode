#include "MainWindow.h"
#include <QApplication>
#include"testDatabase.h"
#include<QTextCodec>
#include<QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#if QT_VERSION >= 0x050000
        QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf8"));
#else
#ifndef Q_OS_WIN
        QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf8"));
#endif
        QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));
        QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));
#endif
    MainWindow w;
    w.show();
    qDebug()<<QCoreApplication::applicationDirPath();
    testDatabase entity;
    entity.test();
    return a.exec();
}
