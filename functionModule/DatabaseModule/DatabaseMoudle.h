#ifndef DATABASEMOUDLE_H
#define DATABASEMOUDLE_H
#include<QString>

#include <QtSql>
namespace ns_DatabaseMoudle {
class DatabaseMoudle
{
public:
    DatabaseMoudle();
    ~DatabaseMoudle();
    bool isOpen();
    static DatabaseMoudle *getConnection(const QString &dbName,
                                         const QString &hostIP,
                                         const QString &port,
                                         const QString &userName=QString(),
                                         const QString &pass=QString(),
                                         QString *pErrMsg=NULL,
                                         const QString &connectionName=QLatin1String(QSqlDatabase::defaultConnection));
    quint32 mobileAlarmGetMySendAlarmHistoryList(QString loginId,QVariantHash &inData,QVariantHash &outData,QString *errorId,QString *errMsg);
    quint32 mobileAlarmGetUserLoginCurrentAuth(QString loginId,QString &currentAuth,QString *errorId,QString *errMsg);

private:
    quint32 checkoutDataBaseIsOpen(QString *errorId,QString *errorMsg);
    quint32 getUserIdFromLoginId_mobile(const QString loginId,QString &userId,QString *errorId,QString *errMsg);

    void changeHashDataToSql_getMobileAlarmHistoryList(QVariantHash inData,QString &sql);
    void setSqlErrorMsg(QSqlQuery &query,QString &sql,QString *errorId,QString *errorMsg);

protected:
    QSqlDatabase m_db;
    QString  m_dbName;
    QString  m_hostIP;
    QString  m_port;
    QString  m_userName;
    QString  m_pass;
    QString  m_connectionName;

    QMutex m_mutex;
};
}


#endif // DATABASEMOUDLE_H
