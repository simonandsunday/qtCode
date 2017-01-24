#include "RpcServerCoreImplementTest.h"
#include<QDebug>
#include<QString>
#include<QDateTime>
#include"testDatabase.h"
#include"JsonToHash.h"
#include"testRpcServer.h"
RpcServerCoreImplementTest::RpcServerCoreImplementTest(handerMode mode):RpcServerCore(mode)
{
}

RpcServerCoreImplementTest::~RpcServerCoreImplementTest()
{

}

void RpcServerCoreImplementTest::receiveData(std::string &_return, const std::string &content)
{
    //_return=QString("receiveData:%1").arg(QString::fromUtf8(content.c_str())).toStdString();
    _return=QString::fromUtf8(content.c_str()).toStdString();

    Qt::HANDLE threadId=this->thread()->currentThreadId();
    if(m_threadMap.contains(threadId)){
        threadMess item=m_threadMap.value(threadId);
        item.count=item.count+1;
        m_threadMap.insert(threadId,item);
    }else{
        threadMess item;
        item.count=1;
        item.num=m_threadMap.size()+1;
        m_threadMap.insert(threadId,item);
    }
    QString printThreadMess=QString("thread num:%1,count:%2").arg(m_threadMap.value(threadId).num).arg(m_threadMap.value(threadId).count);
    INFO_PRINT(AVT_LOG_DEBUG,printThreadMess);
    INFO_PRINT(AVT_LOG_DEBUG,QString("content:%1").arg(QString::fromUtf8(_return.c_str())));
   // qDebug()<<__FILE__<<__func__<<__LINE__<<"this:"<<this<<printThreadMess<<"data:"<<QString::fromUtf8(_return.c_str());
   // this->msleep(500);
    testRpcServer entity;
    entity.distributionInterface(_return,content);
}
