#ifndef SIMPLESDK_H
#define SIMPLESDK_H
#include<QString>

namespace ns_simpleSDK{
class simpleSDK
{
public:
    simpleSDK();
    static bool InitSimpleSDK_Simple(const QString &sdkDirPath, const QString &appPath);
    static int ReleaseSimpleSDK_Simple();
    static bool call_sdk_simple(const int funcId, const QString xmlIn, QString &except, QString* pPresetToken = NULL);
};
}


#endif // SIMPLESDK_H
