
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


#include"RpcClientCore.h"
#include"RpcClient.h"


#include<QVariantHash>
#include"JsonToHash.h"
int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);
    RpcClient entity;
    QString except;
    entity.test("127.0.0.1","9022","fuck,you",except);
    qDebug()<<except;
    return a.exec();
}
