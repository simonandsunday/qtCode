#ifndef RPCSERVERHANDLER_H
#define RPCSERVERHANDLER_H

#include <QObject>
#include "MobileAlarm.h"
#include"HanderInterface.h"
namespace apache
{
namespace thrift
{
namespace server
{
class TThreadPoolServer;
}
}
}
class RpcServerCore;
//class TThreadPoolServer;
class RpcServerHandler : virtual public MOBILE_ALARM_API::MobileAlarmIf,virtual public HanderInterface
{
public:
    RpcServerHandler();
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

    apache::thrift::server::TThreadPoolServer *m_rpcServer;

};

#endif // RPCSERVERHANDLER_H
