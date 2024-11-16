#ifndef HMATH_GLOBAL_H
#define HMATH_GLOBAL_H

#ifndef HMATH_BUILD_STATIC_LIBS

#if defined(_MSC_VER) || defined(WIN64) || defined(_WIN64) || defined(__WIN64__) || defined(WIN32) \
|| defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#define Q_DECL_EXPORT __declspec(dllexport)
#define Q_DECL_IMPORT __declspec(dllimport)
#else
#define Q_DECL_EXPORT __attribute__((visibility("default")))
#define Q_DECL_IMPORT __attribute__((visibility("default")))
#endif

#if defined(HMATH_LIBRARY)
#define HMATH_EXPORT Q_DECL_EXPORT
#else
#define HMATH_EXPORT Q_DECL_IMPORT
#endif

#else
#define HMATH_EXPORT
#endif

#define HMATH_BEGIN_NAMESPACE namespace h {\
                                    namespace math {
#define HMATH_END_NAMESPACE }\
                                }


#endif // HMATH_GLOBAL_H
