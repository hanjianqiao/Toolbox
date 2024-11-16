#ifndef SINGLETONGUARD_H
#define SINGLETONGUARD_H

#include <string>
#if(WIN32)
#include <windows.h>
#else
#endif

#include "hmisc_global.h"

HMISC_BEGIN_NAMESPACE

class HMISC_EXPORT SingletonGuard
{
public:
    SingletonGuard(const std::string &name);
    ~SingletonGuard();

    bool guard();

private:
    std::string m_name;
#if(WIN32)
    HANDLE m_hMutex;
#else
#endif
};

HMISC_END_NAMESPACE

#endif // SINGLETONGUARD_H
