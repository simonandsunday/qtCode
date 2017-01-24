#include "MobileAlarmHandler.h"

#include <QCoreApplication>
#include <QtDebug>
#include <QDateTime>

#include "MobileAlarm.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TNonblockingServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/concurrency/ThreadManager.h>
#ifdef Q_OS_LINUX
#include <thrift/concurrency/PosixThreadFactory.h>
#else
#include <thrift/concurrency/BoostThreadFactory.h>
#endif

#include "RpcServerCore.h"


using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
using namespace ::apache::thrift::concurrency;
using boost::shared_ptr;

using namespace  ::MOBILE_ALARM_API;

MobileAlarmHandler::MobileAlarmHandler() :
    m_rpcServer(NULL),
    m_core(NULL)
{

}

void MobileAlarmHandler::setRpcServerCore(RpcServerCore *core)
{
    m_core = core;
}

void MobileAlarmHandler::AlarmTrigger(std::string& _return, const std::string& content) {
  // Your implementation goes here
  static int counter = 0;
  printf("%d.AlarmTrigger\n", counter++);
  if (NULL != m_core)
    m_core->receiveData(_return, content);
}

void MobileAlarmHandler::AlarmQueryList(std::string& _return, const std::string& content) {
  // Your implementation goes here
    static int counter = 0;
  printf("%d.AlarmQueryList\n", counter++);
  if (NULL != m_core)
    m_core->receiveData(_return, content);
}

void MobileAlarmHandler::AlarmQueryDetail(std::string& _return, const std::string& content) {
  // Your implementation goes here
    static int counter = 0;
  printf("%d.AlarmQueryDetail\n", counter++);
  if (NULL != m_core)
    m_core->receiveData(_return, content);
}

void MobileAlarmHandler::AlarmReset(std::string& _return, const std::string& content) {
  // Your implementation goes here
    static int counter = 0;
    printf("%d.AlarmReset\n", counter++);
    if (NULL != m_core)
      m_core->receiveData(_return, content);
}

int MobileAlarmHandler::StartRPCServer(int port)
{
    if (NULL != m_rpcServer)
    {
        return 1;
    }

#ifdef Q_OS_WIN
    WORD    version(MAKEWORD(2, 2));
    WSAData data;
    memset(&data, 0, sizeof(WSAData));

    int error(WSAStartup(version, &data));
    if (error != 0)
    {
        BOOST_ASSERT(false);
        throw std::runtime_error("Failed to initialise Winsock.");
    }
#endif

    shared_ptr<MobileAlarmHandler> handler(new MobileAlarmHandler());
    handler->setRpcServerCore(m_core);
    shared_ptr<TProcessor> processor(new MobileAlarmProcessor(handler));
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());
    shared_ptr<ThreadManager> threadManager = ThreadManager::newSimpleThreadManager(500);

#ifdef Q_OS_WIN
    shared_ptr<BoostThreadFactory> threadFactory = shared_ptr<BoostThreadFactory > (new BoostThreadFactory());
#else
    shared_ptr<PosixThreadFactory> threadFactory = shared_ptr<PosixThreadFactory > (new PosixThreadFactory());
#endif
    threadManager->threadFactory(threadFactory);
    threadManager->start();
    m_rpcServer = new TNonblockingServer(processor, protocolFactory, port, threadManager);
    m_rpcServer->serve();

#ifdef Q_OS_WIN
    WSACleanup();
#endif

    return 0;
}

int MobileAlarmHandler::StopRPCServer()
{
    if (NULL != m_rpcServer)
    {
        m_rpcServer->stop();
        delete m_rpcServer;
        m_rpcServer = NULL;
    }
    return 0;
}
