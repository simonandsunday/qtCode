#include "MainWindow.h"
#include <QApplication>
#include"readXml.h"
#include<QTextCodec>
#include<QDebug>
#include"InfinovaPage.h"
#include"testForm.h"
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
   // MainWindow w;
    //w.show();
    InfinovaPage page;
    page.show();
    //ns_Infinova_readXml::readXmlTest::testReadFile();
    qDebug()<<__func__<<__LINE__<<"中文";
    //testForm test;
    //test.show();
    return a.exec();
}
