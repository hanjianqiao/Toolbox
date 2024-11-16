#ifndef HMISC_GLOBAL_H
#define HMISC_GLOBAL_H

#ifndef HMISC_BUILD_STATIC_LIBS

#if defined(_MSC_VER) || defined(WIN64) || defined(_WIN64) || defined(__WIN64__) || defined(WIN32) \
|| defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#define Q_DECL_EXPORT __declspec(dllexport)
#define Q_DECL_IMPORT __declspec(dllimport)
#else
#define Q_DECL_EXPORT __attribute__((visibility("default")))
#define Q_DECL_IMPORT __attribute__((visibility("default")))
#endif

#if defined(HMISC_LIBRARY)
#define HMISC_EXPORT Q_DECL_EXPORT
#else
#define HMISC_EXPORT Q_DECL_IMPORT
#endif

#else
#define HMISC_EXPORT
#endif

#define HMISC_BEGIN_NAMESPACE namespace h {\
namespace misc {

#define HMISC_END_NAMESPACE }\
}

#endif // HMISC_GLOBAL_H
