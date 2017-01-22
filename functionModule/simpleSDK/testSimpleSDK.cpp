#include "testSimpleSDK.h"
#include"simpleSDK.h"
#include"XMLString.h"
#include"avt_func_id.h"
namespace ns_simpleSDK{
testSimpleSDK::testSimpleSDK()
{
}

bool testSimpleSDK::InitSimpleSDK_Simple(const QString &sdkDirPath, const QString &appPath)
{
    return ns_simpleSDK::simpleSDK::InitSimpleSDK_Simple(sdkDirPath,appPath);
}

int testSimpleSDK::ReleaseSimpleSDK_Simple()
{
    return ns_simpleSDK::simpleSDK::ReleaseSimpleSDK_Simple();
}

bool testSimpleSDK::nvs_login(const QString &serverIp, const QString &serverPort, const QString &domain, const QString &loginId, const QString &password)
{

    QString xml=QString(XML_LOGIN_SIMPLE_NVS)
            .arg(serverIp)
            .arg(serverPort)
            .arg(domain)
            .arg(loginId)
            .arg(password);
    QString except;
    return ns_simpleSDK::simpleSDK::call_sdk_simple(GB_FUNC_ID_LOGIN,xml,except);

}

bool testSimpleSDK::nvs_logout()
{

    QString xml=QString(XML_LOGOUT_SIMPLE_NVS);
    QString except;
    return ns_simpleSDK::simpleSDK::call_sdk_simple(GB_FUNC_ID_LOGOUT,xml,except);

}

bool testSimpleSDK::nvs_sysGetDeviceList(QString groupId, QString type,QString &except)
{
    QString xml=QString(XML_SYS_GET_DEVICELIST_SIMPLE_NVS)
            .arg(groupId)
            .arg(type);
    return ns_simpleSDK::simpleSDK::call_sdk_simple(AVT_FUNC_ID_GET_DEVICE_LIST_SYNC,xml,except);
}


}
