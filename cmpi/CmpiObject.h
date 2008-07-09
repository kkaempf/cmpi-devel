/*
 *
 * $Id$
 *
 * (C) Copyright IBM Corp. 2003, 2005, 2008
 *
 * THIS FILE IS PROVIDED UNDER THE TERMS OF THE ECLIPSE PUBLIC LICENSE
 * ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE
 * CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
 *
 * You can obtain a current copy of the Eclipse Public License from
 * http://www.opensource.org/licenses/eclipse-1.0.txt
 *
 * Author:        Adrian Schuur <schuur@de.ibm.com>
 * Contributors:  Heidi Neumann, heidineu@de.ibm.com
 *                Angel Nunez Mencias, anunez@de.ibm.com
 *                Viktor Mihajlovski, mihajlov@de.ibm.com
 *
 * Description: CMPI Object Definitions
 *
 */

#ifndef _CmpiObject_h_
#define _CmpiObject_h_

#include "cmpidt.h"
#include "cmpift.h"

#ifndef CmpiBoolean
#define CmpiBoolean CMPIBoolean
#define CmpiRc      CMPIrc
#endif

#include "Linkage.h"
#include "CmpiString.h"

class CmpiBroker;

/** Abstract base class for all Cmpi classes.
*/

class CMPI_PROVIDER_LINKAGE CmpiObject {
   friend class CmpiBroker;
   friend class CmpiObjectPath;
   friend class CmpiInstance;
protected:
   /** Protected pointer to encapsulated CMPI instance
   */
   void *enc;
   /** Constructor - Do nothing
   */
   CmpiObject();

   /** Constructor - Normal base class constructor
   */
   CmpiObject(const void* enc);

   CmpiString doToString(CMPIBroker *mb);

   CmpiBoolean doIsA(CMPIBroker *mb, const char *typeName) const;
private:
public:
   /** isNull - Test for valid encapsualtion pointer
   */
   CmpiBoolean isNull() const;

   /** toString - Produces CIMOM specific string representation of object
   */
   CmpiString toString();

   /** isA - checks this objects type   ;
   */
   CmpiBoolean isA(const char *typeName) const;
};

#endif

