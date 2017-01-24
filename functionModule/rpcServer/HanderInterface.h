#ifndef HANDERINTERFACE_H
#define HANDERINTERFACE_H
#include"RpcServerCore.h"
class HanderInterface
{
public:
    HanderInterface();

   virtual int StartRPCServer(int port = 8977)=0;
   virtual int StopRPCServer()=0;
   virtual void setRpcServerCore(RpcServerCore *core)=0;

};

#endif // HANDERINTERFACE_H
