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
 * Description: CMPI Enumeration Definitions
 *
 */

#ifndef _CmpiEnumeration_h_
#define _CmpiEnumeration_h_

#include "cmpidt.h"
#include "cmpift.h"

#include "Linkage.h"
#include "CmpiObject.h"
#include "CmpiStatus.h"
#include "CmpiObjectPath.h"
#include "CmpiBroker.h"

class CmpiObjectPath;
class CmpiData;

/** This class acts as a container for holding results from enunmerating
    CmpiBroker services.
*/

class CMPI_PROVIDER_LINKAGE CmpiEnumeration : public CmpiObject {
   friend class CmpiBroker;
protected:

   /** Protected constructor used by MIDrivers to encapsulate CMPIEnumeration.
   */
   CmpiEnumeration(CMPIEnumeration* enc);

   /** getEnc - Gets the encapsulated CMPIEnumeration.
   */
   CMPIEnumeration *getEnc() const;

private:

   /** Constructor - Should not be called
   */
   CmpiEnumeration();

public:

   /** getNext - Gets next entry.
   */
   CmpiData getNext();

   /** getNext - Check for at least one remaining entry.
   */
   CmpiBoolean hasNext();

   /** toArray - Convert an Enumeration to an Array
    */
   CmpiData toArray();
};

#endif



