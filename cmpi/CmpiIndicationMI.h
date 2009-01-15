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
 *                Tyrel Datwyler <tyreld@us.ibm.com>
 *
 * Description: CMPI Indication MI Definitions
 *
 */

#ifndef _CmpiIndicationMI_h_
#define _CmpiIndicationMI_h_

#include <iostream>

#include "cmpidt.h"
#include "cmpift.h"

#include "Linkage.h"
#include "CmpiBaseMI.h"
#include "CmpiStatus.h"
#include "CmpiObjectPath.h"
#include "CmpiResult.h"
#include "CmpiContext.h"
#include "CmpiSelectExp.h"


class CMPI_PROVIDER_LINKAGE CmpiIndicationMI : virtual public CmpiBaseMI {
public:
   CmpiIndicationMI(const CmpiBroker &mbp, const CmpiContext& ctx);

   static CMPIStatus driveAuthorizeFilter
   (CMPIIndicationMI* mi, const CMPIContext* eCtx, 
    const CMPISelectExp* se, const char* ns, const CMPIObjectPath* op, 
    const char* user);
   static CMPIStatus driveMustPoll
   (CMPIIndicationMI* mi, const CMPIContext* eCtx, 
    const CMPISelectExp* se, const char* ns, const CMPIObjectPath* op);
   static CMPIStatus driveActivateFilter
   (CMPIIndicationMI* mi, const CMPIContext* eCtx,
    const CMPISelectExp* se, const char* ns, const CMPIObjectPath* op, 
    CMPIBoolean first);
   static CMPIStatus driveDeActivateFilter
   (CMPIIndicationMI* mi, const CMPIContext* eCtx,
    const CMPISelectExp* se, const char* ns, 
    const CMPIObjectPath* op, CMPIBoolean last);
   static CMPIStatus driveEnableIndications
   (CMPIIndicationMI* mi, const CMPIContext* eCtx);
   static CMPIStatus driveDisableIndications
   (CMPIIndicationMI* mi, const CMPIContext* eCtx);

   virtual CmpiStatus authorizeFilter
   (const CmpiContext& ctx, 
    const CmpiSelectExp& se, const char* ns, const CmpiObjectPath& op,
    const char* user);
   virtual CmpiStatus mustPoll
   (const CmpiContext& ctx, 
    const CmpiSelectExp& se, const char* ns, const CmpiObjectPath& op);
   virtual CmpiStatus activateFilter
   (const CmpiContext& ctx, 
    const CmpiSelectExp& se, const char* ns, const CmpiObjectPath& op,
    CmpiBoolean first);
   virtual CmpiStatus deActivateFilter
   (const CmpiContext& ctx, 
    const CmpiSelectExp& se, const char* ns, const CmpiObjectPath& op,
    CmpiBoolean last);
   virtual CmpiStatus enableIndications(const CmpiContext& ctx);
   virtual CmpiStatus disableIndications(const CmpiContext& ctx);
};

#endif

