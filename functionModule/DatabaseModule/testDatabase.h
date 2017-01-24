#ifndef TESTDATABASE_H
#define TESTDATABASE_H
#include"DatabaseMoudle.h"
#include"QThread"
class testDatabase
{
public:
    testDatabase();
    typedef struct tagRestfulHeadData{
        QString loginId;
        QString snId;
        QString auth;
        QString functionId;
        QString v;
    }RestfulHeadData;
    typedef struct tagRestfulGetMobileAlarmHistoryListData{
        QString startTime;
        QString endTime;
        QString alarmType;
        QString alarmLevel;
        QString alarmState;
        QString page_index;
        QString page_size;
    }RestfulGetMobileAlarmHistoryListData;
    void test();
    void test_restful_getMySendAlarmHistoryCaseList(QVariantHash &returnHash,QVariantHash content);
private:
    bool getConnection(ns_DatabaseMoudle::DatabaseMoudle **dbm, const QString &connectionName,QString &errMsg);
    bool commonDetection(QVariantHash &returnHash,QVariantHash content,RestfulHeadData &headDdata,QString &snId,ns_DatabaseMoudle::DatabaseMoudle **dbm,bool isCheckAuth=true);
    bool getRestfulHeadData(RestfulHeadData &headDdata,QVariantHash &returnHash, QVariantHash content);
    bool checkRestfulHead(QVariantHash &returnHash,QVariantHash content);
    bool checkAuth(QVariantHash &returnHash,QVariantHash content);
    bool getUserLoginCurrentAuth(QString loginId,QString &currentAuth,QVariantHash &returnHash,QString snId);
    bool getRestfulGetMobileAlarmHistoryListData(RestfulGetMobileAlarmHistoryListData &data,QVariantHash &returnHash, QVariantHash content,QString snId);
    bool checkfield(QVariantHash &returnHash,QVariantHash content,QString filed,QString snId);

};

#endif // TESTDATABASE_H
