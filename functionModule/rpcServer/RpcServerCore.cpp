#include "RpcServerCore.h"
#include"RpcServerHandler.h"
#include"MobileAlarmHandler.h"
#include<QDebug>
#include"HanderInterface.h"
RpcServerCore::RpcServerCore(handerMode mode,QObject *parent):
    QThread(parent),
    m_rpcServerHander(NULL),
    m_serverPort(8978)
{
    //
    m_mode=mode;
    if(m_mode==handerMode_RpcServer){
        m_rpcServerHander=new RpcServerHandler;
    }else if(m_mode==handerMode_MobileAlarm){
        m_rpcServerHander=new MobileAlarmHandler;
    }
    if(m_rpcServerHander!=NULL){
        m_rpcServerHander->setRpcServerCore(this);
    }
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
    if(m_rpcServerHander!=NULL){
        m_stop = true;
        m_rpcServerHander->StopRPCServer();
        QThread::wait();
    }
}

void RpcServerCore::run()
{
    if(m_rpcServerHander!=NULL){
        m_rpcServerHander->StartRPCServer(m_serverPort);
    }
}
