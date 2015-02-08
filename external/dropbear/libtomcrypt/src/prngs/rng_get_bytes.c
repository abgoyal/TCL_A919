#include "tomcrypt.h"


#ifdef DEVRANDOM
/* on *NIX read /dev/random */
static unsigned long rng_nix(unsigned char *buf, unsigned long len, 
                             void (*callback)(void))
{
#ifdef LTC_NO_FILE
    return 0;
#else
    FILE *f;
    unsigned long x;
#ifdef TRY_URANDOM_FIRST
    f = fopen("/dev/urandom", "rb");
    if (f == NULL)
#endif /* TRY_URANDOM_FIRST */
       f = fopen("/dev/random", "rb");

    if (f == NULL) {
       return 0;
    }
    
    /* disable buffering */
    if (setvbuf(f, NULL, _IONBF, 0) != 0) {
       fclose(f);
       return 0;
    }   
 
    x = (unsigned long)fread(buf, 1, (size_t)len, f);
    fclose(f);
    return x;
#endif /* LTC_NO_FILE */
}

#endif /* DEVRANDOM */

/* on ANSI C platforms with 100 < CLOCKS_PER_SEC < 10000 */
#if defined(CLOCKS_PER_SEC) && !defined(WINCE)

#define ANSI_RNG

static unsigned long rng_ansic(unsigned char *buf, unsigned long len, 
                               void (*callback)(void))
{
   clock_t t1;
   int l, acc, bits, a, b;

   if (XCLOCKS_PER_SEC < 100 || XCLOCKS_PER_SEC > 10000) {
      return 0;
   }

   l = len;
   bits = 8;
   acc  = a = b = 0;
   while (len--) {
       if (callback != NULL) callback();
       while (bits--) {
          do {
             t1 = XCLOCK(); while (t1 == XCLOCK()) a ^= 1;
             t1 = XCLOCK(); while (t1 == XCLOCK()) b ^= 1;
          } while (a == b);
          acc = (acc << 1) | a;
       }
       *buf++ = acc; 
       acc  = 0;
       bits = 8;
   }
   acc = bits = a = b = 0;
   return l;
}

#endif 

/* Try the Microsoft CSP */
#if defined(WIN32) || defined(WINCE)
#define _WIN32_WINNT 0x0400
#ifdef WINCE
   #define UNDER_CE
   #define ARM
#endif
#include <windows.h>
#include <wincrypt.h>

static unsigned long rng_win32(unsigned char *buf, unsigned long len, 
                               void (*callback)(void))
{
   HCRYPTPROV hProv = 0;
   if (!CryptAcquireContext(&hProv, NULL, MS_DEF_PROV, PROV_RSA_FULL, 
                            (CRYPT_VERIFYCONTEXT | CRYPT_MACHINE_KEYSET)) && 
       !CryptAcquireContext (&hProv, NULL, MS_DEF_PROV, PROV_RSA_FULL, 
                            CRYPT_VERIFYCONTEXT | CRYPT_MACHINE_KEYSET | CRYPT_NEWKEYSET))
      return 0;

   if (CryptGenRandom(hProv, len, buf) == TRUE) {
      CryptReleaseContext(hProv, 0);
      return len;
   } else {
      CryptReleaseContext(hProv, 0);
      return 0;
   }
}

#endif /* WIN32 */

unsigned long rng_get_bytes(unsigned char *out, unsigned long outlen, 
                            void (*callback)(void))
{
   unsigned long x;

   LTC_ARGCHK(out != NULL);

#if defined(DEVRANDOM)
   x = rng_nix(out, outlen, callback);   if (x != 0) { return x; }
#endif
#ifdef WIN32
   x = rng_win32(out, outlen, callback); if (x != 0) { return x; }
#endif
#ifdef ANSI_RNG
   x = rng_ansic(out, outlen, callback); if (x != 0) { return x; }
#endif
   return 0;
}

/* $Source: /cvs/libtom/libtomcrypt/src/prngs/rng_get_bytes.c,v $ */
/* $Revision: 1.5 $ */
/* $Date: 2006/12/06 02:01:29 $ */