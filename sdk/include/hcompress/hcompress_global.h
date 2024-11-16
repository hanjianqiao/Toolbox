#ifndef HCOMPRESS_GLOBAL_H
#define HCOMPRESS_GLOBAL_H

#ifndef HCOMPRESS_BUILD_STATIC_LIBS

#if defined(_MSC_VER) || defined(WIN64) || defined(_WIN64) || defined(__WIN64__) || defined(WIN32) \
|| defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#define Q_DECL_EXPORT __declspec(dllexport)
#define Q_DECL_IMPORT __declspec(dllimport)
#else
#define Q_DECL_EXPORT __attribute__((visibility("default")))
#define Q_DECL_IMPORT __attribute__((visibility("default")))
#endif

#if defined(HCOMPRESS_LIBRARY)
#define HCOMPRESS_EXPORT Q_DECL_EXPORT
#else
#define HCOMPRESS_EXPORT Q_DECL_IMPORT
#endif

#else
#define HCOMPRESS_EXPORT
#endif

#define HCOMPRESS_BEGIN_NAMESPACE namespace h {\
                                    namespace compress {
#define HCOMPRESS_END_NAMESPACE }\
                                }


#endif // HCOMPRESS_GLOBAL_H
