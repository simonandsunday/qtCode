#ifndef AVT_BASE_LOG_GLOBAL_H
#define AVT_BASE_LOG_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef AVT_BASE_LOG_LIB
# define AVT_BASE_LOG_EXPORT Q_DECL_EXPORT
#else
# define AVT_BASE_LOG_EXPORT Q_DECL_IMPORT
#endif

#endif // AVT_BASE_LOG_GLOBAL_H
