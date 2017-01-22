#ifndef AVT_BASE_LOG_H
#define AVT_BASE_LOG_H
#include "avt_base_log_global.h"
#include <string>

using namespace std;

typedef enum 
{
	AVT_LOG_EMERG  = 0,		//紧急情况，需要立即通知技术人员。
	AVT_LOG_FATAL  = 0,		//致命错误
	AVT_LOG_ALERT  = 100,	//应该被立即改正的问题，如系统数据库被破坏，ISP连接丢失
	AVT_LOG_CRIT   = 200,	//重要情况，如硬盘错误，备用连接丢失。
	AVT_LOG_ERROR  = 300,	//错误，不是非常紧急，在一定时间内修复即可。
	AVT_LOG_WARN   = 400,	//警告信息，不是错误，比如系统磁盘使用了85%等。
	AVT_LOG_NOTICE = 500,	//不是错误情况，也不需要立即处理。
	AVT_LOG_INFO   = 600,	//情报信息，正常的系统消息，比如骚扰报告，带宽数据等，不需要处理。
	AVT_LOG_DEBUG  = 700,	//包含详细的开发情报的信息，通常只在调试一个程序时使用。
	AVT_LOG_NOTSET = 800	//未设置级别
}AvtLogLevel;

//初始化log4cpp日志,bLocalFile:是否同时记录到本地文件(默认会记录到syslog服务器)
 void InitLog4cpp(const string &strLogName,
									 const string &strSyslogIP, 
									 AvtLogLevel level = AVT_LOG_NOTSET, 
									 unsigned short usSyslogPort = 514, 
									 bool bLocalFile = false);

 void AvtWriteLog(AvtLogLevel level, const std::string& message);
 void AvtWriteLog(AvtLogLevel level, const char* stringFormat, ...);

//释放log4cpp
 void UnInitLog4cpp();

#endif // AVT_BASE_LOG_H
