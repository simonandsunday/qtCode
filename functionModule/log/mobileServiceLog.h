#ifndef MOBILESERVICELOG_H
#define MOBILESERVICELOG_H
#include<QString>
#include "avt_base_log.h"
#define INFO_PRINT(level,str)\
    do\
{\
    QString logInfo = QString("file: %1,func: %2,line:%3,data:%4").arg(QString(__FILE__)).arg(QString(__func__)).arg(QString::number(__LINE__)).arg(str);\
    AvtWriteLog(level, logInfo.toStdString());\
\
}while(0);

#endif // MOBILESERVICELOG_H
