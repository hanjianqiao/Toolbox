#ifndef HFONTAWESOME_GLOBAL_H
#define HFONTAWESOME_GLOBAL_H

#ifndef HFONTAWESOME_BUILD_STATIC_LIBS

#if defined(_MSC_VER) || defined(WIN64) || defined(_WIN64) || defined(__WIN64__) || defined(WIN32) \
|| defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#define Q_DECL_EXPORT __declspec(dllexport)
#define Q_DECL_IMPORT __declspec(dllimport)
#else
#define Q_DECL_EXPORT __attribute__((visibility("default")))
#define Q_DECL_IMPORT __attribute__((visibility("default")))
#endif

#if defined(HFONTAWESOME_LIBRARY)
#define HFONTAWESOME_EXPORT Q_DECL_EXPORT
#else
#define HFONTAWESOME_EXPORT Q_DECL_IMPORT
#endif

#else
#define HFONTAWESOME_EXPORT
#endif

#define HFONTAWESOME_BEGIN_NAMESPACE namespace h {\
                                    namespace fontawesome {
#define HFONTAWESOME_END_NAMESPACE }\
                                }


#endif // HFONTAWESOME_GLOBAL_H
