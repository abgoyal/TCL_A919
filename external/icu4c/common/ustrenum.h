#ifndef _USTRENUM_H_
#define _USTRENUM_H_

#include "unicode/uenum.h"
#include "unicode/strenum.h"

U_CAPI UEnumeration* U_EXPORT2
uenum_openCharStringsEnumeration(const char* const* strings, int32_t count,
                                 UErrorCode* ec);

//----------------------------------------------------------------------
U_NAMESPACE_BEGIN

class U_COMMON_API UStringEnumeration : public StringEnumeration {

public:
    /**
     * Constructor.  This constructor adopts its UEnumeration
     * argument.
     * @param uenum a UEnumeration object.  This object takes
     * ownership of 'uenum' and will close it in its destructor.  The
     * caller must not call uenum_close on 'uenum' after calling this
     * constructor.
     */
    UStringEnumeration(UEnumeration* uenum);

    /**
     * Destructor.  This closes the UEnumeration passed in to the
     * constructor.
     */
    virtual ~UStringEnumeration();

    /**
     * Return the number of elements that the iterator traverses.
     * @param status the error code.
     * @return number of elements in the iterator.
     */
    virtual int32_t count(UErrorCode& status) const;

    /**
     * Returns the next element a UnicodeString*.  If there are no
     * more elements, returns NULL.
     * @param status the error code.
     * @return a pointer to the string, or NULL.
     */
    virtual const UnicodeString* snext(UErrorCode& status);

    /**
     * Resets the iterator.
     * @param status the error code.
     */
    virtual void reset(UErrorCode& status);

    /**
     * ICU4C "poor man's RTTI", returns a UClassID for the actual ICU class.
     */
    virtual UClassID getDynamicClassID() const;

    /**
     * ICU4C "poor man's RTTI", returns a UClassID for this ICU class.
     */
    static UClassID U_EXPORT2 getStaticClassID();

private:
    UEnumeration *uenum; // owned
};

U_NAMESPACE_END

#endif

