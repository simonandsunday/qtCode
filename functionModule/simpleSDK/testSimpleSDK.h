#ifndef TESTSIMPLESDK_H
#define TESTSIMPLESDK_H
#include<QString>
namespace ns_simpleSDK{
class testSimpleSDK
{
public:
    testSimpleSDK();
    static bool InitSimpleSDK_Simple(const QString &sdkDirPath, const QString &appPath);
    static int ReleaseSimpleSDK_Simple();
    static bool nvs_login(const QString &serverIp,const QString &serverPort,const QString &domain,const QString &loginId,const QString &password);
    static bool nvs_logout();
    static bool nvs_sysGetDeviceList(QString groupId,QString type,QString &except);
};
}
#endif // TESTSIMPLESDK_H
