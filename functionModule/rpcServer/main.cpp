
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


#include <QCoreApplication>
#include <QtDebug>
#include <QDateTime>

#include<iostream>
using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::concurrency;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace apache::thrift::server;

#include<MobileAlarm.h>
#include"RpcServerCoreImplementTest.h"
using namespace  ::MOBILE_ALARM_API;

class MobileAlarmHandlerTest:public MobileAlarmIf
{
public:
    MobileAlarmHandlerTest(){}
     void AlarmTrigger(std::string& _return, const std::string& content) {
           cout << "AlarmTrigger: "  << "\n";
           qDebug()<<"AlarmTrigger";
     }
     void AlarmQueryList(std::string& _return, const std::string& content) {

     }
     void AlarmQueryDetail(std::string& _return, const std::string& content){

     }
     void AlarmReset(std::string& _return, const std::string& content){

     }
};

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
        return new MobileAlarmHandlerTest;
    }
    virtual void releaseHandler(MobileAlarmIf *handler){
        delete handler;
    }
};

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);

    RpcServerCoreImplementTest test;
    test.startRpcServerCore(9022);
    return a.exec();
}
