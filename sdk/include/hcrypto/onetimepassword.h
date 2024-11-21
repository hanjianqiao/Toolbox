#ifndef HOTP_H
#define HOTP_H

#include <stdint.h>
#include <string>

#include "hcrypto_global.h"

HCRYPTO_BEGIN_NAMESPACE

class HCRYPTO_EXPORT TimeBasedOTP
{
public:
    static int generatePassword(const std::string &originSecret, uint64_t second);
};

HCRYPTO_END_NAMESPACE

#endif // HOTP_H
