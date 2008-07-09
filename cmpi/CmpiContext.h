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
 * Description: CMPI Context Definitions
 *
 */

#ifndef _CmpiContext_h_
#define _CmpiContext_h_

#include "cmpidt.h"
#include "cmpift.h"

#include "Linkage.h"
#include "CmpiObject.h"
#include "CmpiStatus.h"

/** This class acts as a container to holding provider functions context information.
*/

class CmpiData;

class CMPI_PROVIDER_LINKAGE CmpiContext : public CmpiObject {
   friend class CmpiBroker;
   friend class CmpiInstanceMI;
   friend class CmpiMethodMI;
   friend class CmpiAssociationMI;
   friend class CmpiPropertyMI;
   friend class CmpiIndicationMI;
private:
protected:

   /** Constructor - Should not be called
   */
   CmpiContext();

public:

   /** Constructor used by MIDrivers to encapsulate CMPIContext.
   */
   CmpiContext(CMPIContext* c);

   /** getEnc - Gets the encapsulated CMPIContext.
   */
   CMPIContext *getEnc() const;

   /** invocationFlags - InvocationFlags entry name.
   */
   static const char* invocationFlags;

   /** getEntry - Gets a named context entry.
   */
   CmpiData getEntry(const char* name) const;
};

#endif



