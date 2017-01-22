#include "RpcServerCore.h"
#include"RpcServerHandler.h"
#include<QDebug>
RpcServerCore::RpcServerCore(QObject *parent):
    QThread(parent),
    m_rpcServerHander(NULL),
    m_serverPort(8978)
{
    m_rpcServerHander=new RpcServerHandler;
    m_rpcServerHander->setRpcServerCore(this);
}

RpcServerCore::~RpcServerCore()
{
    if(NULL!=m_rpcServerHander){
        m_rpcServerHander->StopRPCServer();
        delete m_rpcServerHander;
        m_rpcServerHander=NULL;
    }
}

bool RpcServerCore::startRpcServerCore(quint16 serverPort)
{
    if(this->isRunning()){
        qDebug()<<__FILE__<<__func__<<__LINE__<<"startRpcServerCore fail";
        return false;
    }
    m_serverPort = serverPort;
    m_stop = false;

    QThread::start();

    return true;
}

void RpcServerCore::stopThread()
{
    m_stop = true;
    m_rpcServerHander->StopRPCServer();
    QThread::wait();
}

void RpcServerCore::run()
{
    m_rpcServerHander->StartRPCServer(m_serverPort);
}
