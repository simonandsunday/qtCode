#include "RpcClientCore.h"
#include"RpcClientHandler.h"
RpcClientCore::RpcClientCore():m_rpcClientHandler(NULL)
{
    m_rpcClientHandler=new RpcClientHandler;
}

RpcClientCore::~RpcClientCore()
{
    if(m_rpcClientHandler!=NULL){
        m_rpcClientHandler->StopClient();
        delete m_rpcClientHandler;
    }
}

void RpcClientCore::sendData(std::string &_return, const std::string &content)
{
    if(m_rpcClientHandler==NULL){
        return ;
    }
    return m_rpcClientHandler->sendData(_return,content);
}

bool RpcClientCore::startClient(QString destIp, quint16 destPort)
{
    if(m_rpcClientHandler==NULL){
        return false;
    }
    return m_rpcClientHandler->StartClient(destIp,destPort);
}

void RpcClientCore::stopClient()
{
    if(m_rpcClientHandler==NULL){
        return ;
    }
    return m_rpcClientHandler->StopClient();
}
