#ifndef CONVERTER_H
#define CONVERTER_H

#include <woff2/decode.h>
#include <woff2/encode.h>
#include <woff2/output.h>
#include "hcompress_global.h"

HCOMPRESS_BEGIN_NAMESPACE

class Converter
{
public:
    Converter() = delete;

    template<class T1>
    static T1 WOFF2ToTTF(const unsigned char *data, size_t len){
        size_t size = std::min(woff2::ComputeWOFF2FinalSize(data, len), woff2::kDefaultMaxSize);
        // BUGS with WOFF2MemoryOut, the output will change size
        // that is woff2::ComputeWOFF2FinalSize is not correct
        std::string output(size, 0);
        woff2::WOFF2StringOut out(&output);
        const bool ok = woff2::ConvertWOFF2ToTTF(data, len, &out);
        if(ok){
            return T1(output.data(), output.size());
        }else{
            return T1();
        }
    }
};

HCOMPRESS_END_NAMESPACE

#endif // CONVERTER_H
