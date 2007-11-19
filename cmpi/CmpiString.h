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
 * Description: CMPI String Definitions
 *
 */

#ifndef _CmpiString_h_
#define _CmpiString_h_

#include "cmpidt.h"
#include "cmpift.h"
#include <string.h>

#ifndef CMPI_PLATFORM_WIN32_IX86_MSVC
#include <strings.h>
#endif

#ifndef CmpiBoolean
#define CmpiBoolean CMPIBoolean
#define CmpiRc      CMPIrc
#endif

#include "Linkage.h"
#include "CmpiStatus.h"

#ifdef CMPI_PLATFORM_WIN32_IX86_MSVC
#define strcasecmp _stricmp
#endif

/** This class wraps a CIMOM specific string representation.
*/

class CMPI_PROVIDER_LINKAGE CmpiString { //: public CmpiObject {
   friend class CmpiBroker;
   friend class CmpiData;
   friend class CmpiObjectPath;
   friend class CmpiInstance;
   friend class CmpiObject;
   friend class CmpiArgs;
   friend class CmpiArrayIdx;
private:
protected:
   void *enc;
   /** Constructor - Internal use only
   */
   CmpiString(CMPIString* c);

   /** Gets the encapsulated CMPIString.
   */
   CMPIString *getEnc() const;

public:

   /** Constructor - Empty string
   */
   CmpiString();

   /** Constructor - Copy constructor
   */
   CmpiString(const CmpiString& s);

   /** charPtr - get pointer to char* representation
   */
   const char* charPtr() const;

   /** charPtr - Case sensitive compare
   */
   CmpiBoolean equals(const char *str) const;
   CmpiBoolean equals(const CmpiString& str) const;

   /** charPtr - Case insensitive compare
   */
   CmpiBoolean equalsIgnoreCase(const char *str) const;
   CmpiBoolean equalsIgnoreCase(const CmpiString& str) const;
};

#endif


