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
 * Description: CMPI Result Handler Definitions
 *
 */

#ifndef _CmpiResult_h_
#define _CmpiResult_h_

#include "cmpidt.h"
#include "cmpift.h"

#include "Linkage.h"
#include "CmpiObject.h"
#include "CmpiStatus.h"
#include "CmpiData.h"
#include "CmpiInstance.h"
#include "CmpiObjectPath.h"


/** This class acts as a container to hold values returned by provider functions.
*/

class CMPI_PROVIDER_LINKAGE CmpiResult : public CmpiObject{
   friend class CmpiInstanceMI;
   friend class CmpiAssociationMI;
   friend class CmpiMethodMI;
   friend class CmpiPropertyMI;
   friend class CmpiIndicationMI;
private:

   /** Constructor - Should not be called
   */
   CmpiResult();
protected:

   /** Protected constructor used by MIDrivers to encapsulate CMPIResult.
   */
   CmpiResult(CMPIResult* r);

   /** getEnc - Gets the encapsulated CMPIResult.
   */
  CMPIResult *getEnc() const;
  
public:

   /** returnData - Return a CmpiData instance.
   */
   void returnData(const CmpiData& d);

   /** returnData - Return a CmpiInstance object.
   */
   void returnData(const CmpiInstance& d);

   /** returnData - Return a CmpiObjectPath object.
   */
   void returnData(const CmpiObjectPath& d);

   /** returnDone - Indicate all data returned.
   */
   void returnDone();
};

#endif


