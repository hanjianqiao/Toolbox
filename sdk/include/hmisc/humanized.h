#ifndef HUMANIZED_H
#define HUMANIZED_H

#include <stdint.h>
#include <string>
#include "hmisc_global.h"

HMISC_BEGIN_NAMESPACE

class HMISC_EXPORT Humanized
{
public:
    Humanized() = delete;

    static std::string storageSize(uint64_t size);
};

HMISC_END_NAMESPACE

#endif // HUMANIZED_H
