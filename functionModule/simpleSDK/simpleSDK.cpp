#include "simpleSDK.h"
#include<QMutex>
#include"avt_std.h"
#include<QTextCodec>
#include<QDebug>
#include"XMLString.h"
#define XML_BUFSIZE (1024*1024)
namespace ns_simpleSDK{
static QMutex g_initLock;
static int initialed = 0;
static QString g_app_path;

simpleSDK::simpleSDK()
{

}

bool simpleSDK::InitSimpleSDK_Simple(const QString &sdkDirPath, const QString &appPath)
{
    QMutexLocker locker(&g_initLock);
    if(initialed != 0)
        return true;
    g_app_path = appPath;
    QString _sdkDirPath=sdkDirPath;
#ifdef Q_OS_WIN
    _sdkDirPath.replace("/", "\\");
#else
    _sdkDirPath = sdkDirPath;
#endif
        QString xmlIn = QString::fromUtf8(SDK_INIT_STR_SIMPLE).arg(_sdkDirPath);
     //   QString xmlIn;

        bool ret = InitSDK(xmlIn.toUtf8().data());
        if(!ret)
        {
            qDebug()<<__func__<<__LINE__<<"false";
            return false;
        }
        qDebug()<<__func__<<__LINE__<<"true";
        initialed = 1;
        return true;
}

int simpleSDK::ReleaseSimpleSDK_Simple()
{
    if (initialed != 0)
    {
        ReleaseSDK();
    }

    return 0;
}

bool simpleSDK::call_sdk_simple(const int funcId, const QString xmlIn, QString &except, QString *pPresetToken)
{
    QTextCodec *codec = QTextCodec::codecForName("GB18030");
#ifdef Q_OS_LINUX
    QString _xmlIn = codec->fromUnicode(xmlIn);
#else
    QString _xmlIn =   xmlIn;
#endif
    bool ret = false;
    char *lpOut = new char[XML_BUFSIZE];
    memset(lpOut, 0, XML_BUFSIZE);
#ifdef Q_OS_LINUX
    ret = CallSDKEx(funcId, _xmlIn.toLatin1().data(), &lpOut, XML_BUFSIZE);
#else
    ret = CallSDKEx(funcId, _xmlIn.toLocal8Bit().data(), &lpOut, XML_BUFSIZE);
#endif
    except = codec->toUnicode(lpOut);
    delete[] lpOut;
    qDebug() <<__FILE__ << __LINE__ <<__func__<<":"<<xmlIn<<":"<<except<<":"<<ret;
    return ret;
}
}
