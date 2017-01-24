#ifndef RPCSERVERCOREIMPLEMENTTEST_H
#define RPCSERVERCOREIMPLEMENTTEST_H

#include"RpcServerCore.h"
#include"mobileServiceLog.h"
#include<QMap>
class RpcServerCoreImplementTest:public RpcServerCore
{
public:
    typedef struct tagThreadMess{
        int count;
        int num;
    }threadMess;
    RpcServerCoreImplementTest(handerMode mode);
    ~RpcServerCoreImplementTest();
    virtual void receiveData(std::string &_return,const std::string & content);
private:
    QMap<Qt::HANDLE,threadMess> m_threadMap;
};

#endif // RPCSERVERCOREIMPLEMENTTEST_H
