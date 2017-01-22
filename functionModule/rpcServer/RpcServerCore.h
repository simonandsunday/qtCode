#ifndef RPCSERVERCORE_H
#define RPCSERVERCORE_H
#include<QThread>
class RpcServerHandler;
class RpcServerCore:public QThread
{
    Q_OBJECT
public:
    RpcServerCore(QObject *parent = NULL);
    ~RpcServerCore();
    virtual void receiveData(std::string &_return,const std::string & content)=0;

    bool startRpcServerCore(quint16 serverPort);
    void stopThread();
protected:
    void run();
protected:
    bool m_stop;
    quint16 m_serverPort;
    RpcServerHandler *m_rpcServerHander;
};

#endif // RPCSERVERCORE_H
