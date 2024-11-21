#ifndef BASEX_H
#define BASEX_H

#include <string>
#include <vector>
#include "hcrypto_global.h"

HCRYPTO_BEGIN_NAMESPACE

class HCRYPTO_EXPORT BaseX
{
public:
    // rfc4648: The Base16, Base32, and Base64 Data Encodings
    enum Type {
        base16,
        base32,
        base32hex,
        // base36,
        // base58,
        // base62,
        base64,
        base64url,
        // base85,
        // base91,
        // base92,
    };

    BaseX() = delete;

    static std::string encode(Type type, const char *data, size_t len);
    static std::vector<char> decode(Type type, const char *str, size_t len, bool *ok = nullptr);

};

HCRYPTO_END_NAMESPACE

#endif // BASEX_H
