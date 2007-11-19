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
   (CMPIIndicationMI* mi, const CMPIContext* eCtx, const CMPIResult* eRslt,
    const CMPISelectExp* se, const char* ns, const CMPIObjectPath* op, 
    const char* user);
   static CMPIStatus driveMustPoll
   (CMPIIndicationMI* mi, const CMPIContext* eCtx, const CMPIResult* eRrslt,
    const CMPISelectExp* se, const char* ns, const CMPIObjectPath* op);
   static CMPIStatus driveActivateFilter
   (CMPIIndicationMI* mi, const CMPIContext* eCtx, const CMPIResult* eRslt,
    const CMPISelectExp* se, const char* ns, const CMPIObjectPath* op, 
    CMPIBoolean first);
   static CMPIStatus driveDeActivateFilter
   (CMPIIndicationMI* mi, const CMPIContext* eCtx, const CMPIResult* eRslt,
    const CMPISelectExp* se, const char* ns, 
    const CMPIObjectPath* op, CMPIBoolean last);
   static void driveEnableIndications
   (CMPIIndicationMI* mi);
   static void driveDisableIndications
   (CMPIIndicationMI* mi);

   virtual CmpiStatus authorizeFilter
   (const CmpiContext& ctx, CmpiResult& rslt,
    const CmpiSelectExp& se, const char* ns, const CmpiObjectPath& op,
    const char* user);
   virtual CmpiStatus mustPoll
   (const CmpiContext& ctx, CmpiResult& rslt,
    const CmpiSelectExp& se, const char* ns, const CmpiObjectPath& op);
   virtual CmpiStatus activateFilter
   (const CmpiContext& ctx, CmpiResult& rslt,
    const CmpiSelectExp& se, const char* ns, const CmpiObjectPath& op,
    CmpiBoolean first);
   virtual CmpiStatus deActivateFilter
   (const CmpiContext& ctx, CmpiResult& rslt,
    const CmpiSelectExp& se, const char* ns, const CmpiObjectPath& op,
    CmpiBoolean last);
   virtual void enableIndications();
   virtual void disableIndications();
};

#endif

