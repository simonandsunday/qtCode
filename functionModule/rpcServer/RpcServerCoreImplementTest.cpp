#include "RpcServerCoreImplementTest.h"
#include<QDebug>
#include<QString>
RpcServerCoreImplementTest::RpcServerCoreImplementTest()
{
}

RpcServerCoreImplementTest::~RpcServerCoreImplementTest()
{

}

void RpcServerCoreImplementTest::receiveData(std::string &_return, const std::string &content)
{
    _return=QString("receiveData:%1").arg(QString::fromUtf8(content.c_str())).toStdString();
    qDebug()<<__FILE__<<__func__<<__LINE__<<QString::fromUtf8(_return.c_str());
}
