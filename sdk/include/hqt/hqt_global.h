#ifndef HQT_GLOBAL_H
#define HQT_GLOBAL_H

#ifndef HQT_BUILD_STATIC_LIBS
#include <QtCore/qglobal.h>

#if defined(HQT_LIBRARY)
#define HQT_EXPORT Q_DECL_EXPORT
#else
#define HQT_EXPORT Q_DECL_IMPORT
#endif

#else
#define HQT_EXPORT
#endif

#define HQT_BEGIN_NAMESPACE namespace h {\
namespace qt{\

#define HQT_END_NAMESPACE  }\
}\


#endif // HQT_GLOBAL_H
