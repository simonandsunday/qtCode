#include "RpcServerHandler.h"
#include "RpcServerCore.h"
#include<QDebug>

#include <thrift/concurrency/ThreadManager.h>
#include <thrift/concurrency/PlatformThreadFactory.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/server/TThreadPoolServer.h>
#include <thrift/server/TThreadedServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include <thrift/TToString.h>

#include <boost/make_shared.hpp>
#include<iostream>
using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::concurrency;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace apache::thrift::server;

#include<MobileAlarm.h>

using namespace  ::MOBILE_ALARM_API;


class MobileAlarmCloneFactory:virtual public MobileAlarmIfFactory{
public:
    virtual ~MobileAlarmCloneFactory(){}
    virtual MobileAlarmIf * getHandler(const TConnectionInfo &connInfo){
           boost::shared_ptr<TSocket> sock = boost::dynamic_pointer_cast<TSocket>(connInfo.transport);
        cout << "Incoming connection\n";
        cout << "\tSocketInfo: "  << sock->getSocketInfo() << "\n";
        cout << "\tPeerHost: "    << sock->getPeerHost() << "\n";
        cout << "\tPeerAddress: " << sock->getPeerAddress() << "\n";
        cout << "\tPeerPort: "    << sock->getPeerPort() << "\n";
        return new RpcServerHandler;
    }
    virtual void releaseHandler(MobileAlarmIf *handler){
        delete handler;
    }
};
static  RpcServerCore *m_core=NULL;
RpcServerHandler::RpcServerHandler():
  m_rpcServer(NULL)
{

}

void RpcServerHandler::setRpcServerCore(RpcServerCore *core)
{
    m_core=core;
    qDebug()<<__FILE__<<__func__<<__LINE__<<"setRpcServerCore"<<m_core;
}

void RpcServerHandler::AlarmTrigger(std::string &_return, const std::string &content)
{
    qDebug()<<__FILE__<<__func__<<__LINE__<<"AlarmTrigger";
    if(NULL!=m_core){
        m_core->receiveData(_return,content);
    }else{
        qDebug()<<__FILE__<<__func__<<__LINE__<<"m_core is null"<<m_core;
    }
}

void RpcServerHandler::AlarmQueryList(std::string &_return, const std::string &content)
{
    qDebug()<<"AlarmQueryList";
}

void RpcServerHandler::AlarmQueryDetail(std::string &_return, const std::string &content)
{
    qDebug()<<"AlarmQueryDetail";
}

void RpcServerHandler::AlarmReset(std::string &_return, const std::string &content)
{
    qDebug()<<"AlarmReset";
}

int RpcServerHandler::StartRPCServer(int port)
{
    if (NULL != m_rpcServer)
    {
        return 1;
    }

    const int workerCount = 4;
      boost::shared_ptr<ThreadManager> threadManager = ThreadManager::newSimpleThreadManager(workerCount);
      threadManager->threadFactory(boost::make_shared<PlatformThreadFactory>());
      threadManager->start();
      m_rpcServer=new TThreadPoolServer(boost::make_shared<MobileAlarmProcessorFactory>(boost::make_shared<MobileAlarmCloneFactory>()),
                                      boost::make_shared<TServerSocket>(port),
                                      boost::make_shared<TBufferedTransportFactory>(),
                                      boost::make_shared<TBinaryProtocolFactory>(),
                                      threadManager);

      cout << "server: "  << "\n";
      qDebug()<<__FILE__<<__func__<<__LINE__<<"startRpcServerCore is succeed";
      m_rpcServer->serve();
}

int RpcServerHandler::StopRPCServer()
{
    if (NULL != m_rpcServer)
    {
        m_rpcServer->stop();
        delete m_rpcServer;
        m_rpcServer = NULL;
    }
    return 0;
}
