#include "testDatabase.h"
#include<QDebug>
#include<QDateTime>
#define qdebugEx qDebug()<<__func__<<__LINE__
testDatabase::testDatabase()
{
}

void testDatabase::test()
{
    QString dbName = QString::number((qulonglong)QThread::currentThreadId());
    ns_DatabaseMoudle::DatabaseMoudle *_dbm = NULL;
    QString error;
    qint64 history=QDateTime::currentMSecsSinceEpoch();
    qdebugEx<<"start:"<<QDateTime::currentMSecsSinceEpoch()-history;
    bool flag=this->getConnection(&_dbm,dbName,error);
    if(flag==false){
        qdebugEx<<"connection database false,"<<error;
        return;
    }else{
        qdebugEx<<"connection database success";
    }
    QString loginId=QString("18998387201");
    QVariantHash indata;
    QVariantHash outdata;
    QString *errorId;
    QString *errorMsg;
    indata.insert("alarmType","0,1,2");
    indata.insert("alarmLevel","0,1");
    indata.insert("alarmState","0,1,2,3,4,5,6");
    indata.insert("page_index","1");
    indata.insert("page_size","100");
    int ret=_dbm->mobileAlarmGetMySendAlarmHistoryList(loginId,indata,outdata,errorId,errorMsg);
    if(ret!=0){
        qdebugEx<<"errorId:"<<errorId<<"errorMsg:"<<errorMsg;
        return;
    }
    qdebugEx<<"end:"<<QDateTime::currentMSecsSinceEpoch()-history;
}

void testDatabase::test_restful_getMySendAlarmHistoryCaseList(QVariantHash &returnHash,QVariantHash content)
{
    qint64 history=QDateTime::currentMSecsSinceEpoch();
    qdebugEx<<"start:"<<QDateTime::currentMSecsSinceEpoch()-history;
    bool bRet;
    RestfulHeadData headData;
    ns_DatabaseMoudle::DatabaseMoudle *_dbm = NULL;
    QString snId=content.value("SNID").toString();
    bRet=commonDetection(returnHash,content,headData,snId,&_dbm);
    if(bRet==false){
        return;
    }
    RestfulGetMobileAlarmHistoryListData entityData;
    bRet=getRestfulGetMobileAlarmHistoryListData(entityData,returnHash,content,snId);
    if(bRet==false){
        return;
    }
    QVariantHash datahash=content.value("DATA").toHash();
    QString errorId;
    QString errorMsg;
    int ret;
    QVariantHash outData;
    ret=_dbm->mobileAlarmGetMySendAlarmHistoryList(headData.loginId,datahash,outData,&errorId,&errorMsg);
    if(ret!=0){
        returnHash.insert("snId", snId);
        returnHash.insert("detail",errorMsg);
        returnHash.insert("errorId", errorId);
        returnHash.insert("data",   "");
        return ;
    }
    returnHash.insert("snId", snId);
    returnHash.insert("detail","");
    returnHash.insert("errorId", 10000);
    returnHash.insert("data",   outData);


    qdebugEx<<"end:"<<QDateTime::currentMSecsSinceEpoch()-history;
    return;
}

bool testDatabase::getConnection(ns_DatabaseMoudle::DatabaseMoudle **dbm, const QString &connectionName,QString &errMsg)
{
    *dbm = ns_DatabaseMoudle::DatabaseMoudle::getConnection("aip",
                                            "127.0.0.1",
                                            "3306",
                                            "root",
                                            "aip@mysql",
                                            &errMsg,
                                            connectionName);

    if (!(*dbm))
    {
        return false;
    }

    return true;
}

bool testDatabase::commonDetection(QVariantHash &returnHash, QVariantHash content, testDatabase::RestfulHeadData &headData, QString &snId, ns_DatabaseMoudle::DatabaseMoudle **dbm, bool isCheckAuth)
{
    bool bRet;
    //检测数据通用头
    bRet=getRestfulHeadData(headData,returnHash,content);
    if(bRet==false){
        qDebug()<<__func__<<__LINE__<<returnHash;
        return false;
    }
    //step 检测用户的合法性
    if(isCheckAuth==true){
        if(!checkAuth(returnHash,content)){
            qDebug()<<__func__<<__LINE__<<returnHash;
            return false;
        }
    }

    //step 检测连接到数据库

    QString dbName = QString::number((qulonglong)QThread::currentThreadId());
    //INFO_PRINT(AVT_LOG_INFO,dbName);
    snId=content.value("SNID").toString();
    QString errorMsg;
    if(false == this->getConnection(dbm, dbName,errorMsg))
    {

        returnHash.insert("snId", snId);
        returnHash.insert("detail",    QString("连接数据库失败"));
        returnHash.insert("errorId",   10004);
        returnHash.insert("data",   QVariantHash());
        qDebug()<<__func__<<__LINE__<<returnHash;
        return false;
    }
    return true;
}

bool testDatabase::getRestfulHeadData(testDatabase::RestfulHeadData &headDdata, QVariantHash &returnHash, QVariantHash content)
{
    bool ret;
    ret=checkRestfulHead(returnHash,content);
    if(ret==false){
        return false;
    }
    headDdata.loginId=content.value("LOGINID").toString();
    headDdata.snId=content.value("SNID").toString();
    headDdata.auth=content.value("AUTH").toString();
    headDdata.functionId=content.value("FUNCTIONID").toString();
    headDdata.v=content.value("V").toString();
    return true;
}

bool testDatabase::checkRestfulHead(QVariantHash &returnHash, QVariantHash content)
{
    QString snId;
    if(!content.contains("SNID")){
        returnHash.insert("snId", "");
        returnHash.insert("detail",    QString("缺乏SNID字段"));
        returnHash.insert("errorId",   10001);
        returnHash.insert("data",   "");
        return false;
    }else{
        snId=returnHash.value("SNID").toString();
    }

    bool ret;
    ret=checkfield(returnHash,content,"LOGINID",snId);
    if(ret==false){
        return false;
    }
    ret=checkfield(returnHash,content,"AUTH",snId);
    if(ret==false){
        return false;
    }
    ret=checkfield(returnHash,content,"V",snId);
    if(ret==false){
        return false;
    }
    ret=checkfield(returnHash,content,"DATA",snId);
    if(ret==false){
        return false;
    }
    return true;
}

bool testDatabase::checkAuth(QVariantHash &returnHash, QVariantHash content)
{
    QString loginId;
    QString auth;
    QString snId;
    loginId=content.value("LOGINID").toString();
    auth=content.value("AUTH").toString();
    snId=content.value("SNID").toString();
    QString currentAuth;
    qDebug()<<__func__<<__LINE__<<"TEST";
    bool bRet=getUserLoginCurrentAuth(loginId,currentAuth,returnHash,snId);
    qDebug()<<__func__<<__LINE__<<"TEST";
    if(bRet==false){
        return false;
    }
    if(auth==currentAuth){
        //do nothing
        return true;
    }else{
        returnHash.insert("snId", snId);
        returnHash.insert("detail",    QString("用户认证失败,请使用正确的auth字段"));
        returnHash.insert("errorId",   10003);
        returnHash.insert("data",   QVariantHash());

    }
    return false;
}

bool testDatabase::getUserLoginCurrentAuth(QString loginId, QString &currentAuth, QVariantHash &returnHash, QString snId)
{
    ns_DatabaseMoudle::DatabaseMoudle *_dbm = NULL;
    QString errorId;
    QString errorMsg;
    int ret;

    QString dbName = QString::number((qulonglong)QThread::currentThreadId());

    if(false == this->getConnection(&_dbm, dbName,errorMsg))
    {

        returnHash.insert("snId", snId);
        returnHash.insert("detail",    QString("连接数据库失败"));
        returnHash.insert("errorId",   10004);
        returnHash.insert("data",   QVariantHash());
        qDebug()<<__func__<<__LINE__<<returnHash;
        return false;
    }

    ret=_dbm->mobileAlarmGetUserLoginCurrentAuth(loginId,currentAuth,&errorId,&errorMsg);
    if(ret!=0){
        returnHash.insert("snId", snId);
        returnHash.insert("detail",    errorMsg);
        returnHash.insert("errorId",   errorId);
        returnHash.insert("data",   QVariantHash());
        return false;
    }else{
        return true;
    }
}

bool testDatabase::getRestfulGetMobileAlarmHistoryListData(testDatabase::RestfulGetMobileAlarmHistoryListData &data, QVariantHash &returnHash, QVariantHash content, QString snId)
{
    QVariantHash datahash=content.value("DATA").toHash();
    data.startTime=datahash.value("STARTTIME").toString();
    data.endTime=datahash.value("ENDTIME").toString();
    data.alarmType=datahash.value("ALARMTYPE").toString();
    data.alarmLevel=datahash.value("ALARMLEVEL").toString();
    data.alarmState=datahash.value("ALARMSTATE").toString();
    data.page_index=datahash.value("PAGE_INDEX").toString();
    data.page_size=datahash.value("PAGE_SIZE").toString();
    return true;
}

bool testDatabase::checkfield(QVariantHash &returnHash, QVariantHash content, QString filed, QString snId)
{
    if(!content.contains(filed)){
        returnHash.insert("snId", snId);
        returnHash.insert("detail",    QString("缺乏%1字段").arg(filed));
        returnHash.insert("errorId",   10001);
        returnHash.insert("data",   "");
        return false;
    }else{
        return true;
    }
}
