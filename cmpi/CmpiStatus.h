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
 *                Viktor Mihajlovski, mihajlov@de.ibm.com
 *
 * Description: CMPI Status Definitions
 *
 */

#ifndef _CmpiStatus_h_
#define _CmpiStatus_h_

#include "cmpidt.h"
#include "cmpift.h"

#include "Linkage.h"
#include "CmpiBaseMI.h"

/** This class represents the status of a provider function invocation.
*/

class CMPI_PROVIDER_LINKAGE CmpiStatus {
   friend class CmpiInstanceMI;
   friend class CmpiMethodMI;
   friend class CmpiBaseMI;
   friend class CmpiAssociationMI;
   friend class CmpiPropertyMI;
   friend class CmpiIndicationMI;
protected:

   /** CmpiStatus actually is a CMPIStatus struct.
   */
   CMPIStatus st;

   /** status - Returns CMPIStatus struct, to be used by MI drivers only.
   */
   CMPIStatus status() const;

private:

   /** Constructor - not to be used.
   */
   CmpiStatus();

public:

   /** Aux Constructor - set from CMPIStatus.
       @param stat the CMPIStatus
   */
   CmpiStatus(const CMPIStatus stat);

   /** Constructor - set rc only.
       @param rc the return code.
   */
   CmpiStatus(const CMPIrc rc);

   /** Constructor - set rc and message.
       @param rc The return code.
       @param msg Descriptive message.
   */
   CmpiStatus(const CMPIrc rcp, const char *msg);

   /** rc - get the rc value.
   */
   CMPIrc rc() const;

   /** msg - get the msg component.
   */
   const char*  msg();
};

#endif



