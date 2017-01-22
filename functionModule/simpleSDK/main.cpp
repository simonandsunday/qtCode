#include "MainWindow.h"
#include <QApplication>
#include"testSimpleSDK.h"
#include<QDebug>
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
    qDebug()<<__func__<<__LINE__<<"start";
    QString sdkDirPath=qApp->applicationDirPath()+"/StandardSDK";
    QString appPath=qApp->applicationDirPath();
    ns_simpleSDK::testSimpleSDK::InitSimpleSDK_Simple(sdkDirPath,appPath);
    QString serverIp=QString("219.134.189.138");
    QString port=QString("8830");
    QString domain=QString("szjyjy.gjj.gd");
    QString loginId=QString("szgjj");
    QString password=QString("sz123456");
    ns_simpleSDK::testSimpleSDK::nvs_login(serverIp,port,domain,loginId,password);
    QString groupId=QString("");
    QString type=QString("3");
    QString except;
    ns_simpleSDK::testSimpleSDK::nvs_sysGetDeviceList(groupId,type,except);
    ns_simpleSDK::testSimpleSDK::nvs_logout();
    return a.exec();
}
