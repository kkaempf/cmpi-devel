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
 * http://oss.software.ibm.com/developerworks/opensource/license-cpl.html
 *
 * Author:        Adrian Schuur <schuur@de.ibm.com>
 * Contributors:  Heidi Neumann, heidineu@de.ibm.com
 *                Angel Nunez Mencias, anunez@de.ibm.com
 *
 * Description: CMPI Array Definitions
 *
 */

#ifndef _CmpiArray_h_
#define _CmpiArray_h_

#include "cmpidt.h"
#include "CmpiString.h"

#include "Linkage.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBaseMI.h"
#include "CmpiData.h"

class CmpiArray;
class CmpiInstance;
class CmpiData;

class CMPI_PROVIDER_LINKAGE CmpiArrayIdx {
   friend class CmpiArray;
   const CmpiArray &ar;
   CMPICount idx;
   CmpiArrayIdx(const CmpiArray &a, CMPICount i);
public:
   CmpiArrayIdx& operator=(const CmpiData&);
   CmpiData getData() const;

   /** Extracting String.
   */
   operator CmpiString() const;
   /** Extracting const char *
   */
   operator const char* () const;
   /** Extracting CmpiDataTime.
   */
   operator CmpiDateTime() const;
   /** Extracting CmpiInstance.
   */
   operator CmpiInstance() const;
   /** Extracting CmpiObjectPath.
   */
   operator CmpiObjectPath() const;
   /** Extracting CMPISint8.
   */
   operator CMPISint8() const;
   /** Extracting signed 16 bit.
   */
   operator CMPISint16() const;
   /** Extracting signed 32 bit.
   */
   operator CMPISint32() const;
   /** Extracting signed 32 bit.
   */
   operator int() const;
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
   /** Extracting unsigned 32 bit.
   */
   operator unsigned int() const;
   /** Extracting unsigned 64 bit.
   */
   operator CMPIUint64() const;
   /** Extracting float 32 bit.
   */
   operator CMPIReal32() const;
   /** Extracting float 64 bit.
   */
   operator CMPIReal64() const;

};


/** This class wraps a CMPIData value array.
      Index operations use the [] operator.
      Data extraction uses type conversion operators.
      Extraction operations can be appended to an array indexing operation
      like this:

        CmpiString state;

 CmpiArray states;

        states=ci.getProperty("States");

 state=states[3];

 Assignment statements use array indexing operations as well:

 states[5]="offline";

       Type mismatches will be signalled by exceptions.
*/

class CmpiArray : public CmpiObject {
   friend class CmpiArrayIdx;
   friend class CmpiData;
   friend class CmpiEnumeration;
   void operator=(int x);

   /** Gets the encapsulated CMPIArray.
   */
   CMPIArray *getEnc() const;
   void *makeArray(CMPIBroker *mb,CMPICount max, CMPIType type);
   CmpiArray(CMPIArray *arr);
public:
   CmpiArray(CMPICount max, CMPIType type);
   CmpiArray();
   CMPICount size() const;
   CmpiArrayIdx operator[](int idx) const;
};

#endif



