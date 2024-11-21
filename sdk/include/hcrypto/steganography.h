#ifndef STEGANOGRAPHY_H
#define STEGANOGRAPHY_H

#include <stdint.h>
#include "hcrypto_global.h"

HCRYPTO_BEGIN_NAMESPACE


// 64 bytes
struct SteganoHeader {
    uint8_t  sig[4];       // File Signature (HIDE)
    uint16_t version;      // Format Version
    uint8_t  level;        // Encoding level
    uint8_t  flags;        // Flags
    uint32_t offset;       // Offset to data
    uint32_t size;         // Size of data
    uint32_t hash;         // CRC32 hash of data
    uint8_t  name[32];     // File name, unused space filled with zeros
    uint8_t  reserved[12]; // Must be filled with zeros
    uint8_t data[0];       // pointer to decrypted data
};
static_assert(sizeof(SteganoHeader) == 64);

class HCRYPTO_EXPORT Steganography
{
public:
    Steganography() = delete;
};

class HCRYPTO_EXPORT SteganographyPlainLSB
{
public:
    SteganographyPlainLSB() = delete;

    static size_t maxBytesCanWrite(size_t destSize);
    static bool readHeader(const unsigned char *buf, size_t bufLen, SteganoHeader *out);
    static void encrypt(
        const char *name,
        const unsigned char *data, size_t dataLen,
        unsigned char *dest, size_t destLen,
        const unsigned char *password, size_t passwordLen);
    static SteganoHeader *decrypt(
        const unsigned char *buf, size_t bufLen,
        const unsigned char *password, size_t passwordLen);

private:
    static void read(const unsigned char *data, size_t dataLen, unsigned char *out, size_t *outLen);
    static void write(const unsigned char *data, size_t dataLen, unsigned char *dest, size_t destLen);
};

HCRYPTO_END_NAMESPACE

#endif // STEGANOGRAPHY_H
