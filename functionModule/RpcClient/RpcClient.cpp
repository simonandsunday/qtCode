#include "RpcClient.h"

#include"RpcClientCore.h"
RpcClient::RpcClient()
{
}

void RpcClient::test(QString ip,QString port, QString content, QString &except)
{
    RpcClientCore clientCore;
    clientCore.startClient(ip,port.toInt());
    std::string string_returnData;
    std::string string_content=content.toStdString();
    clientCore.sendData(string_returnData,string_content);
    except=QString::fromUtf8(string_returnData.c_str());
    clientCore.stopClient();
    return;
}
