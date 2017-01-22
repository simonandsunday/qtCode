#include "avt_base_log.h"

#include <QtCore/QCoreApplication>
#include <QDir>

//log4cpp
#define LOG4CPP_HAVE_SYSLOG	1
#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/RemoteSyslogAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/SyslogAppender.hh>
#include <log4cpp/PropertyConfigurator.hh>
#include <log4cpp/Layout.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/NDC.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/RollingFileAppender.hh>

//全局日志变量
log4cpp::Category *g_pLog = NULL;

using namespace log4cpp;

 void InitLog4cpp(const string &strLogName,
									 const string &strSyslogIP,  
									 AvtLogLevel level /*= NOTSET*/, 
									 unsigned short usSyslogPort /*= 514*/, 
									 bool bLocalFile /*= false*/)
{
	if (g_pLog)
	{
		UnInitLog4cpp();
	}

	log4cpp::Category& root =log4cpp::Category::getRoot();
	log4cpp::Category& infoCategory = root.getInstance(strLogName);//空间名
	g_pLog = &infoCategory;

	//syslog
	if (!strSyslogIP.empty())
	{
		log4cpp::Appender* syslogAppender = new log4cpp::RemoteSyslogAppender("RemoteSyslogAppender", strLogName, strSyslogIP, LOG_USER, usSyslogPort);

		//%d时间,%p级别,%c空间名,%x按NDC（Nested Diagnostic Context，线程堆栈）顺序输出日志,%m显示输出消息,%n当前平台下的换行符
		log4cpp::PatternLayout* pLayout = new log4cpp::PatternLayout();		
		pLayout->setConversionPattern("[%t]%x%m%n");
		syslogAppender->setLayout(pLayout);

		infoCategory.addAppender(syslogAppender);
		infoCategory.setPriority(level);
	}

	//local file log
	if(bLocalFile)
	{
		//创建本地日志目录
        QString strPath =  QCoreApplication::applicationDirPath();
        QDir dir(strPath);
        dir.cdUp();
        dir.setPath(QString("%1/log").arg(dir.path()));
        strPath = dir.path();
        if(dir.exists() || dir.mkpath(strPath) == true)
        {
            strPath.append("/");
            strPath.append(strLogName.c_str());
            strPath.append(".log");

            log4cpp::Appender* rollfileAppender = new log4cpp::RollingFileAppender("rollfileAppender", strPath.toLocal8Bit().constData(), 5*1024*1024, 5);

            //%d时间,%p级别,%c空间名,%x按NDC（Nested Diagnostic Context，线程堆栈）顺序输出日志,%m显示输出消息,%n当前平台下的换行符,"%t"输出记录器所在的线程ID
            log4cpp::PatternLayout* pLayout = new log4cpp::PatternLayout();
            pLayout->setConversionPattern("[%d][%-6p%x] [%t]%m%n");
            rollfileAppender->setLayout(pLayout);

            infoCategory.addAppender(rollfileAppender);
            infoCategory.setPriority(level);
        }
	}
}

 void UnInitLog4cpp()
{
	g_pLog = NULL;
	log4cpp::Category::shutdown();
}

 void AvtWriteLog(AvtLogLevel level, const std::string& message)
{
	if (NULL == g_pLog)
	{
		return;
	}

	try
	{
		switch (level)
		{
		case AVT_LOG_EMERG://FATAL也认为是EMERG,两者同一级别
			g_pLog->emerg(message);
			break;

		case AVT_LOG_ALERT:
			g_pLog->alert(message);
			break;

		case AVT_LOG_CRIT:
			g_pLog->crit(message);
			break;

		case AVT_LOG_ERROR:
			g_pLog->error(message);
			break;

		case AVT_LOG_WARN:
			g_pLog->warn(message);
			break;

		case AVT_LOG_NOTICE:
			g_pLog->notice(message);
			break;

		case AVT_LOG_INFO:
			g_pLog->info(message);
			break;

		case AVT_LOG_DEBUG:
			g_pLog->debug(message);
			break;

		case AVT_LOG_NOTSET://未定义的错误不写入
		default:
			break;
		}
	}
	catch(...)
	{

	}
}

 void AvtWriteLog(AvtLogLevel level, const char* stringFormat, ...)
{
	if (NULL == g_pLog || NULL == stringFormat)
	{
		return;
	}

	try
	{
		switch (level)
		{
		case AVT_LOG_EMERG://FATAL也认为是EMERG,两者同一级别
			{
				va_list va;
				va_start(va, stringFormat);
				g_pLog->logva(Priority::EMERG, stringFormat, va);
				va_end(va);
			}
			break;

		case AVT_LOG_ALERT:
			{
				va_list va;
				va_start(va, stringFormat);
				g_pLog->logva(Priority::ALERT, stringFormat, va);
				va_end(va);
			}
			break;

		case AVT_LOG_CRIT:
			{
				va_list va;
				va_start(va, stringFormat);
				g_pLog->logva(Priority::CRIT, stringFormat, va);
				va_end(va);
			}
			break;

		case AVT_LOG_ERROR:
			{
				va_list va;
				va_start(va, stringFormat);
				g_pLog->logva(Priority::ERROR, stringFormat, va);
				va_end(va);
			}
			break;

		case AVT_LOG_WARN:
			{
				va_list va;
				va_start(va, stringFormat);
				g_pLog->logva(Priority::WARN, stringFormat, va);
				va_end(va);
			}
			break;

		case AVT_LOG_NOTICE:
			{
				va_list va;
				va_start(va, stringFormat);
				g_pLog->logva(Priority::NOTICE, stringFormat, va);
				va_end(va);
			}
			break;

		case AVT_LOG_INFO:
			{
				va_list va;
				va_start(va, stringFormat);
				g_pLog->logva(Priority::INFO, stringFormat, va);
				va_end(va);
			}
			break;

		case AVT_LOG_DEBUG:
			{
				va_list va;
				va_start(va, stringFormat);
				g_pLog->logva(Priority::DEBUG, stringFormat, va);
				va_end(va);
			}
			break;

		case AVT_LOG_NOTSET://未定义的错误不写入
		default:
			break;
		}
	}
	catch(...)
	{

	}
}
