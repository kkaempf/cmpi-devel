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
 * Description: CMPI Select Expression Definitions
 *
 */

#ifndef _CmpiSelectExp_h_
#define _CmpiSelectExp_h_

#include "cmpidt.h"
#include "cmpift.h"

#include "Linkage.h"

#include "CmpiObject.h"
#include "CmpiStatus.h"
#include "CmpiObjectPath.h"
#include "CmpiBroker.h"
#include "CmpiData.h"

class CmpiObjectPath;

/** This class represents the SelectExp of a CIM class. It is used manipulate
    SelectExps and their parts.
*/

class CMPI_PROVIDER_LINKAGE CmpiSelectExp : public CmpiObject {
   friend class CmpiBroker;
   friend class CmpiResult;
   friend class CmpiIndicationMI;
protected:

   /** Protected constructor used by MIDrivers to encapsulate CMPISelectExp.
   */
   CmpiSelectExp(const CMPISelectExp* enc);

   /** Gets the encapsulated CMPISelectExp.
   */
   CMPISelectExp *getEnc() const;

private:

   /** Constructor - Should not be called
   */
   CmpiSelectExp();
public:
};

#endif
