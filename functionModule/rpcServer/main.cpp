
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

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);

    RpcServerCoreImplementTest test;
    test.startRpcServerCore(9022);
    //test.startRpcServerCore(8977);
    return a.exec();
}
