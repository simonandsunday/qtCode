#ifndef RPCCLIENTCORE_H
#define RPCCLIENTCORE_H
#include<QString>
#include "rpcclient_global.h"
class RpcClientHandler;
class RPCCLIENTSHARED_EXPORT RpcClientCore
{
public:
    RpcClientCore();
    ~RpcClientCore();
    void sendData(std::string &_return,const std::string & content);
    bool startClient(QString destIp,quint16 destPort);
    void stopClient();
protected:
    RpcClientHandler *m_rpcClientHandler;
};



#endif // RPCCLIENTCORE_H
