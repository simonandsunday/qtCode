#include "DatabaseMoudle.h"
#include<QMutex>
#include<QHash>
//#define DBLOCK {QMutexLocker locker(&m_mutex);{
#define DBLOCK {{
#define DBUNLOCK }}

#define INDEXOF(X) int index_##X = temp.indexOf(#X);
#define DBVALUE(X) query.value(index_##X)
namespace ns_DatabaseMoudle {
QMutex g_mutex;
QHash<QString, DatabaseMoudle *> g_dbm_hash;
DatabaseMoudle::DatabaseMoudle()
{
}

DatabaseMoudle::~DatabaseMoudle()
{
    if (m_db.isOpen())
    {
        m_db.close();
    }
}

DatabaseMoudle *DatabaseMoudle::getConnection(const QString &dbName, const QString &hostIP, const QString &port, const QString &userName, const QString &pass, QString *pErrMsg, const QString &connectionName)
{
    QMutexLocker locker(&g_mutex);
    qDebug() << __FILE__ << __LINE__ << QSqlDatabase::drivers();
    DatabaseMoudle *dbm = NULL;
    for(;;){
        if(g_dbm_hash.contains(connectionName)){
            dbm=g_dbm_hash.value(connectionName);
            if(hostIP==dbm->m_hostIP&&port==dbm->m_port){
                return dbm;
            }
            delete dbm;
            dbm=NULL;
            g_dbm_hash.remove(connectionName);
            break;
        }
        break;
    }
    if(!dbm){
        dbm=new DatabaseMoudle;
    }
    if(QSqlDatabase::contains(connectionName)){
        dbm->m_db=QSqlDatabase::database(connectionName,false);
        if(dbm->m_db.isOpen()&&dbm->m_db.isValid()){
            dbm->m_db.close();
            dbm->m_db.setConnectOptions();
        }
    }else{
        dbm->m_db=QSqlDatabase::addDatabase("QMYSQL",connectionName);
    }
    dbm->m_db.setDatabaseName(dbName);
    dbm->m_db.setHostName(hostIP);
    dbm->m_db.setPort(port.toUShort());
    dbm->m_db.setUserName(userName);
    dbm->m_db.setPassword(pass);

    QString reconnect = QString("MYSQL_OPT_RECONNECT=%1").arg(1);
    dbm->m_db.setConnectOptions(reconnect);//set reconnect

    if (!dbm->m_db.open())
    {
        QString _errMsg = dbm->m_db.lastError().text();
        dbm->m_db.setConnectOptions();
        if (pErrMsg)
        {
            *pErrMsg = _errMsg;
        }
//        //qDebug() << __FILE__ << __LINE__ << _errMsg;
        delete dbm;
        return NULL;
    }

    dbm->m_dbName = dbName;
    dbm->m_hostIP = hostIP;
    dbm->m_port = port;
    dbm->m_userName = userName;
    dbm->m_pass = pass;
    dbm->m_connectionName = connectionName;

    g_dbm_hash.insert(connectionName, dbm);

    return dbm;
}

quint32 DatabaseMoudle::mobileAlarmGetMySendAlarmHistoryList(QString loginId, QVariantHash &inData, QVariantHash &outData, QString *errorId, QString *errMsg)
{
    int ret;
    ret=checkoutDataBaseIsOpen(errorId,errMsg);
    if(ret!=0){
        return 1;
    }
    QString userId;
    if(getUserIdFromLoginId_mobile(loginId,userId,errorId,errMsg)!=0){
        return 1;
    }
    bool bRet = false;
    QString sql;
    DBLOCK
            QSqlQuery query(m_db);
    QString conditions;
    changeHashDataToSql_getMobileAlarmHistoryList(inData,conditions);
    if(conditions.size()!=0){
        sql=QString("select *from v_mobile_alarm_getAlarmComment_via_reporterId where v_alarmReportId ='%1' and %2").arg(userId).arg(conditions);
    }else{
        sql=QString("select *from v_mobile_alarm_getAlarmComment_via_reporterId where v_alarmReportId ='%1'").arg(userId);
    }
    bRet = query.exec(sql);
    if(!bRet){
        setSqlErrorMsg(query,sql,errorId,errMsg);
        return 2;
    }
    QSqlRecord temp = query.record();
    INDEXOF(v_commentCaseId);
    INDEXOF(v_isComment);
    INDEXOF(v_total);
    QString caseId;
    QString totals;
    QString isComment;
    QString commentSize=QString::number(query.size());
    QVariantHash commentHash;
    while (query.next())
    {
        caseId = DBVALUE(v_commentCaseId).toString();
        totals=DBVALUE(v_total).toString();
        isComment=DBVALUE(v_isComment).toString();
        QVariantHash CommentContext;
        CommentContext.insert("total",totals);
        CommentContext.insert("isComment",isComment);
        commentHash.insert(caseId,CommentContext);
    }
    qDebug()<<__func__<<__LINE__<<"commentHash size:"<<commentHash.size()<<commentHash;





    if(conditions.size()!=0){
        sql=QString("select *from v_mobile_alarm_getMysendAlarm_history_list where %1 and v_alarmReportId='%2' ORDER BY v_alarmTime DESC").arg(conditions).arg(userId);
    }else{
        sql=QString("select *from v_mobile_alarm_getMysendAlarm_history_list where v_alarmReportId='%1' ORDER BY v_alarmTime DESC").arg(userId);
    }
    bRet = query.exec(sql);

    if(!bRet){
        setSqlErrorMsg(query,sql,errorId,errMsg);
        return 2;
    }


    QString total=QString::number( query.size());

    QString unCommentSize=QString::number(total.toInt()-commentSize.toInt());
    if(total=="0"){
        QVariantList listHash;
        outData.insert("list",listHash);
        outData.insert("size",0);
        outData.insert("total",0);
        return 0;
    }

    QString page_index=inData.value("PAGE_INDEX").toString();
    QString page_size=inData.value("PAGE_SIZE").toString();
    QString startPoint;
    QString pointSize;

    if(page_index.size()==0){
        page_index=QString("1");
    }
    if(page_size.size()==0){
        page_size=QString("100");
    }
    if(page_index.toInt()<0||page_index==0){
        *errorId=QString("10050");
        *errMsg=QString("参数page_index有误");
        return false;
    }
    startPoint=QString::number((page_index.toLongLong()-1)*page_size.toLongLong());
    pointSize=page_size;
    sql=QString("%1 limit %2,%3").arg(sql).arg(startPoint).arg(pointSize);
    bRet = query.exec(sql);

    if(!bRet){
        setSqlErrorMsg(query,sql,errorId,errMsg);
        return 2;
    }

    QString size=QString::number( query.size());
    temp = query.record();
    //先确定Index，这样操作效率会更高
    INDEXOF(v_caseId);
    INDEXOF(v_level);
    INDEXOF(v_alarmTime);
    INDEXOF(v_alarmStartTime);
    INDEXOF(v_reporterName);
    INDEXOF(v_alarmLocation);
    INDEXOF(v_alarmState);
    INDEXOF(v_alarmType);
    INDEXOF(v_tribeId);

    //QString caseId;
    QString alarmTime;
    QString name;
    QString level;
    QString currentTime;
    QString alarmLocation;
    QString alarmState;
    QString alarmType;
    QString tribeId;

    QVariantList listHash;
    while (query.next())
    {
        caseId = DBVALUE(v_caseId).toString();
        alarmTime =DBVALUE(v_alarmStartTime).toString();
        currentTime=DBVALUE(v_alarmTime).toString();
        name=DBVALUE(v_reporterName).toString();
        level=DBVALUE(v_level).toString();
        alarmLocation=DBVALUE(v_alarmLocation).toString();
        alarmState=DBVALUE(v_alarmState).toString();
        alarmType=DBVALUE(v_alarmType).toString();
        tribeId=DBVALUE(v_tribeId).toString();
        QVariantHash itemHash;
        itemHash.insert("caseId",caseId);
        itemHash.insert("level",level);
        itemHash.insert("name",name);
        itemHash.insert("alarmTime",alarmTime);
        itemHash.insert("currentTime",currentTime);
        itemHash.insert("alarmLocation",alarmLocation);
        itemHash.insert("alarmState",alarmState);
        itemHash.insert("alarmType",alarmType);
        itemHash.insert("yunWangCaseId",tribeId);
        if(commentHash.contains(caseId)){
            QVariantHash item=commentHash.value(caseId).toHash();
            qDebug()<<__func__<<__LINE__<<"caseId:"<<caseId;
            if(item.value("isComment").toInt()==1){
                itemHash.insert("isComment","true");
                itemHash.insert("commentLevel",item.value("total").toString());

            }else{
                itemHash.insert("isComment","false");
                itemHash.insert("commentLevel","");
            }
        }else{
            itemHash.insert("isComment","false");
            itemHash.insert("commentLevel","");
        }
        listHash.append(itemHash);
    }
    outData.insert("list",listHash);
    outData.insert("size",size);
    outData.insert("total",total);
    outData.insert("unCommentSize",unCommentSize);
    DBUNLOCK
            return 0;
}

quint32 DatabaseMoudle::mobileAlarmGetUserLoginCurrentAuth(QString loginId, QString &currentAuth, QString *errorId, QString *errMsg)
{
    if (!m_db.isOpen() || !m_db.isValid())
    {
        if(NULL != errMsg)
        {
            *errMsg = QString("连接数据库失败");
        }
        if(NULL!=errorId){
            *errorId=QString("10004");
        }
        return 1;
    }
    QString userId;
    if(getUserIdFromLoginId_mobile(loginId,userId,errorId,errMsg)!=0){
        return 1;
    }


    bool bRet = false;
    QString sql;
    DBLOCK
            QSqlQuery query(m_db);

    sql =QString("select * from monitor_mobile_alarm_user_auth where userId = '%1'").arg(userId);
    bRet = query.exec(sql);
    if (!bRet)
    {
        QString _errMsg = query.lastError().text();
        if (errMsg){
            *errMsg = _errMsg;
        }

        if(NULL!=errorId){
            *errorId=QString("10005");
        }
        return 2;
    }
    QSqlRecord temp = query.record();
    //先确定Index，这样操作效率会更高
    INDEXOF(auth);
    while (query.next())
    {
        currentAuth = DBVALUE(auth).toString();
        break;
    }
    DBUNLOCK
            return 0;
}

quint32 DatabaseMoudle::checkoutDataBaseIsOpen(QString *errorId, QString *errorMsg)
{
    if (!m_db.isOpen() || !m_db.isValid())
    {
        if(NULL != errorMsg)
        {
            *errorMsg = QString("连接数据库失败");
        }
        if(NULL!=errorId){
            *errorId=QString("10004");
        }
        return 1;
    }
    return 0;
}

quint32 DatabaseMoudle::getUserIdFromLoginId_mobile(const QString loginId, QString &_userId, QString *errorId, QString *errMsg)
{
    bool bRet = false;
    QString sql;
    DBLOCK
            QSqlQuery query(m_db);

    sql =QString("select userId from monitor_mobile_user_base_info where registerId = '%1'").arg(loginId);
    bRet = query.exec(sql);
    if (!bRet)
    {
        QString _errMsg = query.lastError().text();
        if (errMsg){
            *errMsg = _errMsg;
        }

        if(NULL!=errorId){
            *errorId=QString("10005");
        }
        return 2;
    }
    if(query.size()==0){
        //用户不存在
        if (errMsg){
            *errMsg = QString("用户在数据库中不存在");
        }

        if(NULL!=errorId){
            *errorId=QString("10006");
        }
        return 3;
    }else if(query.size()==1){
        //唯一用户
        QSqlRecord temp = query.record();
        //先确定Index，这样操作效率会更高
        INDEXOF(userId);
        while (query.next())
        {
            _userId = DBVALUE(userId).toString();
            break;
        }
    }else{
        //重复用户
        if (errMsg){
            *errMsg = QString("用户重复注册");
        }
        if(NULL!=errorId){
            *errorId=QString("10007");
        }
        return 4;
    }
    DBUNLOCK
            return 0;
}

void DatabaseMoudle::changeHashDataToSql_getMobileAlarmHistoryList(QVariantHash inData, QString &conditions)
{
    QString startTime=inData.value("STARTTIME").toString();
    QString endTime=inData.value("ENDTIME").toString();
    QString alarmType=inData.value("ALARMTYPE").toString();
    QString alarmLevel=inData.value("ALARMLEVEL").toString();
    QString alarmState=inData.value("ALARMSTATE").toString();

    if(startTime.size()!=0){
            QDateTime startDateTime=QDateTime::fromTime_t(startTime.toLongLong());
            QString startTimeString=startDateTime.toString("yyyy-MM-dd hh:mm:ss");
            if(conditions.size()==0){
               conditions=QString(" v_alarmTime>'%1'").arg(startTimeString);
            }else {
                conditions.append(QString(" and v_alarmTime>'%1'").arg(startTimeString));
            }
    }
    if(endTime.size()!=0){
        QDateTime endDateTime=QDateTime::fromTime_t(endTime.toLongLong());
        QString endTimeString=endDateTime.toString("yyyy-MM-dd hh:mm:ss");
        if(conditions.size()==0){
            conditions=QString(" v_alarmTime<'%1'").arg(endTimeString);
        }else{
            conditions.append(QString(" and v_alarmTime<'%1'").arg(endTimeString));
        }
    }
    if(alarmType.size()!=0){
        QStringList itemList=alarmType.split(",");
        for(int i=0;i<itemList.size();i++){
            if(i==0){
                if(conditions.size()==0){
                    conditions.append(QString(" ( v_alarmType=%1").arg(itemList.at(i)));
                }else {
                    conditions.append(QString(" and ( v_alarmType=%1").arg(itemList.at(i)));
                }
            }else{
                conditions.append(QString(" or v_alarmType=%1").arg(itemList.at(i)));
            }
        }
        conditions.append(")");
    }
    if(alarmLevel.size()!=0){
        QStringList itemList=alarmLevel.split(",");
        for(int i=0;i<itemList.size();i++){
            if(i==0){
                if(conditions.size()==0){
                    conditions.append(QString(" ( v_level=%1").arg(itemList.at(i)));
                }else {
                    conditions.append(QString(" and ( v_level=%1").arg(itemList.at(i)));
                }
            }else{
                conditions.append(QString(" or v_level=%1").arg(itemList.at(i)));
            }
        }
        conditions.append(")");
    }
    if(alarmState.size()!=0){
        QStringList itemList=alarmState.split(",");
        for(int i=0;i<itemList.size();i++){
            if(i==0){
                if(conditions.size()==0){
                    conditions.append(QString(" ( v_alarmState=%1").arg(itemList.at(i)));
                }else {
                    conditions.append(QString(" and ( v_alarmState=%1").arg(itemList.at(i)));
                }
            }else{
                conditions.append(QString(" or v_alarmState=%1").arg(itemList.at(i)));
            }
        }
        conditions.append(")");
    }
    return;
}

void DatabaseMoudle::setSqlErrorMsg(QSqlQuery &query, QString &sql, QString *errorId, QString *errorMsg)
{
    QString _errMsg = query.lastError().text();
    if (errorMsg){
        *errorMsg = QString("%1,sql:%2/数据库操作失败").arg(_errMsg).arg(sql);
    }

    if(NULL!=errorId){
        *errorId=QString("10005");
    }
}
}
