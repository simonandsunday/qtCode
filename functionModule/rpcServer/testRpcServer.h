#ifndef TESTRPCSERVER_H
#define TESTRPCSERVER_H
#include<QThread>
class testRpcServer
{
public:
    testRpcServer();
    void distributionInterface(std::string& _return, const std::string& content);

};

#endif // TESTRPCSERVER_H
