#include "MainWindow.h"
#include <QApplication>
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
    InitLog4cpp("log", "", AVT_LOG_DEBUG, 514, true);
    INFO_PRINT(AVT_LOG_DEBUG,"log test 中文");
    w.show();

    return a.exec();
}
