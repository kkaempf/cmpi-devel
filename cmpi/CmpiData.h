/*
 *
 * $Id$
 *
 * (C) Copyright IBM Corp. 2003, 2005
 *
 * THIS FILE IS PROVIDED UNDER THE TERMS OF THE COMMON PUBLIC LICENSE
 * ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE
 * CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
 *
 * You can obtain a current copy of the Common Public License from
 * http://www.opensource.org/licenses/cpl1.0.txt
 *
 * Author:        Adrian Schuur <schuur@de.ibm.com>
 * Contributors:  Heidi Neumann, heidineu@de.ibm.com
 *                Angel Nunez Mencias, anunez@de.ibm.com
 *                Viktor Mihajlovski, mihajlov@de.ibm.com
 *
 * Description: CMPI Data Definitions
 *
 */

#ifndef _CmpiData_h_
#define _CmpiData_h_

#include "cmpidt.h"
#include "cmpift.h"

#include "Linkage.h"
#include "CmpiString.h"
#include "CmpiDateTime.h"

class CmpiInstance;
class CmpiObjectPath;

#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiArray.h"

class CmpiBooleanData;
class CmpiCharData;


/** This class wraps a CMPIData value item. Data extraction uses type conversion operators.
      Extraction operations can be appended to a property type retrieval statement
      like this:
 
        CmpiString name = cop.getKey("DeviceID");
 
       Type mismatches will be signalled by exceptions.
*/
class CMPI_PROVIDER_LINKAGE CmpiData {
   friend class CmpiInstance;
   friend class CmpiObjectPath;
   friend class CmpiResult;
   friend class CmpiArgs;
   friend class CmpiArrayIdx;
   friend class CmpiContext;
   friend class CmpiPropertyMI;
   friend class CmpiEnumeration;
protected:

   /** CmpiData actually is a CMPIData struct.
   */
   CMPIData _data;

   /** Constructor - Empty constructor.
   */
   CmpiData(CMPIData& data);

public:

   /** Constructor - Empty constructor.
   */
   CmpiData();

   /** Constructor - singed 8 bit as input.
   */
   CmpiData(CMPISint8 d);

   /** Constructor - singed 16 bit as input.
   */
   CmpiData(CMPISint16 d);

   /** Constructor - singed 32 bit as input.
   */
   CmpiData(CMPISint32 d);

   /** Constructor - singed 64 bit as input.
   */
   CmpiData(CMPISint64 d);

   /** Constructor - unsinged 8 bit as input.
   */
   CmpiData(CMPIUint8 d);

   /** Constructor - unsinged 16 bit as input.
   */
   CmpiData(CMPIUint16 d);

   /** Constructor - unsinged 32 bit as input.
   */
   CmpiData(CMPIUint32 d);

   /** Constructor - unsinged 64 bit as input.
   */
   CmpiData(CMPIUint64 d);

   /** Constructor - 32 bit float as input.
   */
   CmpiData(CMPIReal32 d);

   /** Constructor - 64 bit float as input.
   */
   CmpiData(CMPIReal64 d);

   /** Constructor - String as input.
   */
   CmpiData(const CmpiString& d);

   /** Constructor - char* as input.
   */
   CmpiData(const char* d);

   /** Constructor - ObjectPath as input.
   */
   CmpiData(const CmpiObjectPath& d);


   /** Constructor - DateTime as input.
   */
   CmpiData(const CmpiDateTime& d);

   /** Constructor - Array as input.
   */
   CmpiData(const CmpiArray& d);

   /** Extracting String.
   */
    operator CmpiString() const;

   /** Extracting const char *.
   */
    operator const char* () const;

   /** Extracting CmpiDataTime.
   */
   operator CmpiDateTime() const;

   /** Extracting signed 8 bit.
   */
   operator CMPISint8() const;
   /** Extracting signed 16 bit.
   */
   operator CMPISint16() const;

   /** Extracting signed 32 bit.
   */
   operator CMPISint32() const;

   /** Extracting signed 64 bit.
   */
   operator CMPISint64() const;

   /** Extracting unsigned 8 bit or boolean.
   */
   operator unsigned char() const;

   /** Extracting unsigned 16 bit or char16.
   */
   operator unsigned short() const;

   /** Extracting unsigned 32 bit.
   */
   operator CMPIUint32() const;

   /** Extracting unsigned 64 bit.
   */
   operator CMPIUint64() const;

   /** Extracting float 32 bit.
   */
   operator CMPIReal32() const;

   /** Extracting float 64 bit.
   */
   operator CMPIReal64() const;

   /** Extracting Array.
   */
   operator CmpiArray() const;

   /** Extracting Instance.
   */
   operator CmpiInstance() const;

   /** Extracting ObjectPath.
   */
   operator CmpiObjectPath() const;

   /** test for null value
   */
   int isNullValue() const;

   /** test for not found value
   */
   int isNotFound() const;
};

#endif



