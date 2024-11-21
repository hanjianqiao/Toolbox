#ifndef HCRYPTO_GLOBAL_H
#define HCRYPTO_GLOBAL_H

#ifndef HCRYPTO_BUILD_STATIC_LIBS

#if defined(_MSC_VER) || defined(WIN64) || defined(_WIN64) || defined(__WIN64__) || defined(WIN32) \
|| defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#define Q_DECL_EXPORT __declspec(dllexport)
#define Q_DECL_IMPORT __declspec(dllimport)
#else
#define Q_DECL_EXPORT __attribute__((visibility("default")))
#define Q_DECL_IMPORT __attribute__((visibility("default")))
#endif

#if defined(HCRYPTO_LIBRARY)
#define HCRYPTO_EXPORT Q_DECL_EXPORT
#else
#define HCRYPTO_EXPORT Q_DECL_IMPORT
#endif

#else
#define HCRYPTO_EXPORT
#endif

#define HCRYPTO_BEGIN_NAMESPACE namespace h {\
    namespace crypto {
#define HCRYPTO_END_NAMESPACE }\
}


#endif // CRYPTO_GLOBAL_H
