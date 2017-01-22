#include "RpcClientHandler.h"
#include"RpcClientCore.h"

#include<QDebug>

#include <iostream>
#include<stdio.h>
#include <QCoreApplication>
#include <QTextCodec>

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using namespace  ::MOBILE_ALARM_API;
RpcClientHandler::RpcClientHandler()
{
}

RpcClientHandler::~RpcClientHandler()
{

}


void RpcClientHandler::sendData(std::string &_return, const std::string &content)
{
    boost::shared_ptr<TTransport> socket(new TSocket(m_destIp.toStdString(), m_destPort));
    boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
    boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
    MOBILE_ALARM_API::MobileAlarmClient client(protocol);
    try {
      transport->open();

      client.AlarmTrigger(_return,content);
      cout << "AlarmTrigger log" <<content << endl;
      transport->close();
    } catch (TException& tx) {
      cout << "ERROR: " << tx.what() << endl;
    }

}

bool RpcClientHandler::StartClient(QString destIp, int destPort)
{
    m_destPort=destPort;
    m_destIp=destIp;
    return true;
}

void RpcClientHandler::StopClient()
{

}
