#ifndef RPCCLIENTHANDLER_H
#define RPCCLIENTHANDLER_H
#include<QString>
#include<MobileAlarm.h>
class RpcClientCore;

class RpcClientHandler
{
public:
    RpcClientHandler();
    ~RpcClientHandler();
    void sendData(std::string& _return, const std::string& content);
private:
    bool StartClient(QString destIp,int destPort = 8977);
    void StopClient();
protected:
    friend class RpcClientCore;
private:
    QString m_destIp;
    int m_destPort;
};

#endif // RPCCLIENTHANDLER_H
