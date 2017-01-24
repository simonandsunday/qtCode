#ifndef MOBILEALARMHANDLER_H
#define MOBILEALARMHANDLER_H

#include "MobileAlarm.h"
#include"HanderInterface.h"
namespace apache
{
namespace thrift
{
namespace server
{
class TNonblockingServer;
}
}
}

class RpcServerCore;

//这个类新建之后，启动rpcserver的话，是重新new一个出来的，本身不参与业务，详细看StartRPCServer
class MobileAlarmHandler : virtual public MOBILE_ALARM_API::MobileAlarmIf,virtual public HanderInterface
{
public:
    MobileAlarmHandler();

    void setRpcServerCore(RpcServerCore *core);

    void AlarmTrigger(std::string& _return, const std::string& content);

    void AlarmQueryList(std::string& _return, const std::string& content);

    void AlarmQueryDetail(std::string& _return, const std::string& content);

    void AlarmReset(std::string& _return, const std::string& content);

private:
    int StartRPCServer(int port = 8977);
    int StopRPCServer();

protected:
    friend class RpcServerCore;
  apache::thrift::server::TNonblockingServer *m_rpcServer;

  RpcServerCore *m_core;
};

#endif // MOBILEALARMHANDLER_H
