#include "MainWindow.h"
#include <QApplication>
#include"JsonToHash.h"
#include <QVariantHash>
#include<QDebug>
#include"mobileServiceLog.h"
#include<QTextCodec>
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
    QVariantHash hash;
    QVariantHash dataHash;
    dataHash.insert("functionId","1000");
    hash.insert("data",dataHash);
    JsonToHash toHash;
    QString datastr=toHash.AnalysisHashToJSON(hash);
    qDebug()<<__LINE__<<datastr;
    QVariantHash testHash=toHash.AnalysisJSONToHash(datastr);
    qDebug()<<__LINE__<<testHash;
    InitLog4cpp("log", "", AVT_LOG_INFO, 514, true);
    INFO_PRINT(AVT_LOG_DEBUG,datastr);
    return a.exec();
}
