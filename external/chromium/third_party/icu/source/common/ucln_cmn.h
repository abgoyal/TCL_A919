
#ifndef __UCLN_CMN_H__
#define __UCLN_CMN_H__

#include "unicode/utypes.h"
#include "ucln.h"

/* These are the cleanup functions for various APIs. */
/* @return true if cleanup complete successfully.*/
U_CFUNC UBool umtx_cleanup(void);

U_CFUNC UBool utrace_cleanup(void);

U_CFUNC UBool ucln_lib_cleanup(void);

typedef enum ECleanupCommonType {
    UCLN_COMMON_START = -1,
    UCLN_COMMON_USPREP,
    UCLN_COMMON_BREAKITERATOR,
    UCLN_COMMON_BREAKITERATOR_DICT,
    UCLN_COMMON_SERVICE,
    UCLN_COMMON_URES,
    UCLN_COMMON_LOCALE,
    UCLN_COMMON_ULOC,
    UCLN_COMMON_UNORM,
    UCLN_COMMON_USET,
    UCLN_COMMON_UNAMES,
    UCLN_COMMON_PNAME,
    UCLN_COMMON_UPROPS,
    UCLN_COMMON_UBIDI,
    UCLN_COMMON_UCASE,
    UCLN_COMMON_UCHAR,
    UCLN_COMMON_UCNV,
    UCLN_COMMON_UCNV_IO,
    UCLN_COMMON_UDATA,
    UCLN_COMMON_PUTIL,
    UCLN_COMMON_COUNT /* This must be last */
} ECleanupCommonType;

/* Main library cleanup registration function. */
/* See common/ucln.h for details on adding a cleanup function. */
U_CFUNC void U_EXPORT2 ucln_common_registerCleanup(ECleanupCommonType type,
                                                   cleanupFunc *func);

#endif
