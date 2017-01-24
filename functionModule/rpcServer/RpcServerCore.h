#ifndef RPCSERVERCORE_H
#define RPCSERVERCORE_H
#include<QThread>
class RpcServerHandler;
class MobileAlarmHandler;
class HanderInterface;
class RpcServerCore:public QThread
{
    Q_OBJECT
public:
    enum handerMode{
        handerMode_RpcServer=1,
        handerMode_MobileAlarm=2
    };
    RpcServerCore(handerMode mode,QObject *parent = NULL);
    ~RpcServerCore();
    virtual void receiveData(std::string &_return,const std::string & content)=0;

    bool startRpcServerCore(quint16 serverPort);
    void stopThread();
protected:
    void run();
protected:
    bool m_stop;
    quint16 m_serverPort;
    //RpcServerHandler *m_rpcServerHander;
    //MobileAlarmHandler *m_rpcServerHander;
    HanderInterface *m_rpcServerHander;
    handerMode m_mode;
};

#endif // RPCSERVERCORE_H
