
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
#include"mobileServiceLog.h"
#include<QTextCodec>
using namespace  ::MOBILE_ALARM_API;

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);

#if QT_VERSION >= 0x050000
        QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf8"));
#else
#ifndef Q_OS_WIN
        QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf8"));
#endif
        QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));
        QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));
#endif

    RpcServerCoreImplementTest test(RpcServerCore::handerMode_MobileAlarm);
    //RpcServerCoreImplementTest test(RpcServerCore::handerMode_RpcServer);
    InitLog4cpp("rpcServer", "", AVT_LOG_DEBUG, 514, true);
    INFO_PRINT(AVT_LOG_DEBUG,"rpcServer start");
    int port=9022;
    test.startRpcServerCore(port);

    INFO_PRINT(AVT_LOG_DEBUG,QString("rpcServer start port:%1").arg(port));
    return a.exec();
}
