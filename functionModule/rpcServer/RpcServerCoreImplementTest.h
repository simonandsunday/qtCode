#ifndef RPCSERVERCOREIMPLEMENTTEST_H
#define RPCSERVERCOREIMPLEMENTTEST_H

#include"RpcServerCore.h"
class RpcServerCoreImplementTest:public RpcServerCore
{
public:
    RpcServerCoreImplementTest();
    ~RpcServerCoreImplementTest();
    virtual void receiveData(std::string &_return,const std::string & content);
};

#endif // RPCSERVERCOREIMPLEMENTTEST_H
