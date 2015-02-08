

#include "config.h"
#include "PixelDumpSupportCG.h"

#include "DumpRenderTree.h"
#include "PixelDumpSupport.h"
#include <ImageIO/CGImageDestination.h>
#include <algorithm>
#include <ctype.h>
#include <wtf/Assertions.h>
#include <wtf/RefPtr.h>
#include <wtf/RetainPtr.h>
#include <wtf/StringExtras.h>

#if PLATFORM(WIN)
#include "MD5.h"
#elif PLATFORM(MAC)
#include <LaunchServices/UTCoreTypes.h>
#define COMMON_DIGEST_FOR_OPENSSL
#include <CommonCrypto/CommonDigest.h>
#endif

using namespace std;

#if PLATFORM(WIN)
static const CFStringRef kUTTypePNG = CFSTR("public.png");
#endif

static void printPNG(CGImageRef image)
{
    RetainPtr<CFMutableDataRef> imageData(AdoptCF, CFDataCreateMutable(0, 0));
    RetainPtr<CGImageDestinationRef> imageDest(AdoptCF, CGImageDestinationCreateWithData(imageData.get(), kUTTypePNG, 1, 0));
    CGImageDestinationAddImage(imageDest.get(), image, 0);
    CGImageDestinationFinalize(imageDest.get());

    const UInt8* data = CFDataGetBytePtr(imageData.get());
    CFIndex dataLength = CFDataGetLength(imageData.get());

    printPNG(static_cast<const unsigned char*>(data), static_cast<size_t>(dataLength));
}

void computeMD5HashStringForBitmapContext(BitmapContext* context, char hashString[33])
{
    CGContextRef bitmapContext = context->cgContext();

    ASSERT(CGBitmapContextGetBitsPerPixel(bitmapContext) == 32); // ImageDiff assumes 32 bit RGBA, we must as well.
    size_t pixelsHigh = CGBitmapContextGetHeight(bitmapContext);
    size_t pixelsWide = CGBitmapContextGetWidth(bitmapContext);
    size_t bytesPerRow = CGBitmapContextGetBytesPerRow(bitmapContext);

    // We need to swap the bytes to ensure consistent hashes independently of endianness
    MD5_CTX md5Context;
    MD5_Init(&md5Context);
    unsigned char* bitmapData = static_cast<unsigned char*>(CGBitmapContextGetData(bitmapContext));
#if PLATFORM(MAC)
    if ((CGBitmapContextGetBitmapInfo(bitmapContext) & kCGBitmapByteOrderMask) == kCGBitmapByteOrder32Big) {
        for (unsigned row = 0; row < pixelsHigh; row++) {
            uint32_t buffer[pixelsWide];
            for (unsigned column = 0; column < pixelsWide; column++)
                buffer[column] = OSReadLittleInt32(bitmapData, 4 * column);
            MD5_Update(&md5Context, buffer, 4 * pixelsWide);
            bitmapData += bytesPerRow;
        }
    } else
#endif
    {
        for (unsigned row = 0; row < pixelsHigh; row++) {
            MD5_Update(&md5Context, bitmapData, 4 * pixelsWide);
            bitmapData += bytesPerRow;
        }
    }
    unsigned char hash[16];
    MD5_Final(hash, &md5Context);

    hashString[0] = '\0';
    for (int i = 0; i < 16; i++)
        snprintf(hashString, 33, "%s%02x", hashString, hash[i]);
}

void dumpBitmap(BitmapContext* context)
{
    RetainPtr<CGImageRef> image(AdoptCF, CGBitmapContextCreateImage(context->cgContext()));
    printPNG(image.get());
}