#ifndef RPCCLIENT_H
#define RPCCLIENT_H

#include "rpcclient_global.h"

class RPCCLIENTSHARED_EXPORT RpcClient
{

public:
    RpcClient();
    void test(QString ip,QString port,QString content,QString &except);
};

#endif // RPCCLIENT_H
