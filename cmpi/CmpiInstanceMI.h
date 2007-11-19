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
 * Description:   CMPI Instance MI Definitions
 *
 */

#ifndef _CmpiInstanceMI_h_
#define _CmpiInstanceMI_h_

#include <iostream>

#include "cmpidt.h"
#include "cmpift.h"

#include "Linkage.h"
#include "CmpiBaseMI.h"
#include "CmpiStatus.h"
#include "CmpiString.h"
#include "CmpiData.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiResult.h"
#include "CmpiContext.h"

class CMPI_PROVIDER_LINKAGE CmpiInstanceMI : virtual public CmpiBaseMI {
public:
   CmpiInstanceMI(const CmpiBroker &mbp, const CmpiContext& ctx);

   static CMPIStatus driveEnumInstanceNames
   (CMPIInstanceMI* mi, const CMPIContext* eCtx, const CMPIResult* eRslt,
    const CMPIObjectPath* eCop);
   static CMPIStatus driveEnumInstances
   (CMPIInstanceMI* mi, const CMPIContext* eCtx, const CMPIResult* eRslt,
    const CMPIObjectPath* eCop, const char* *properties);
   static CMPIStatus driveGetInstance
   (CMPIInstanceMI* mi, const CMPIContext* eCtx, const CMPIResult* eRslt,
    const CMPIObjectPath* eCop, const char* *properties);
   static CMPIStatus driveCreateInstance
   (CMPIInstanceMI* mi, const CMPIContext* eCtx, const CMPIResult* eRslt,
    const CMPIObjectPath* eCop, const CMPIInstance* eInst);
   static CMPIStatus driveSetInstance
   (CMPIInstanceMI* mi, const CMPIContext* eCtx, const CMPIResult* eRslt,
    const CMPIObjectPath* eCop, const CMPIInstance* eInst, 
    const char* *properties);
   static CMPIStatus driveDeleteInstance
   (CMPIInstanceMI* mi, const CMPIContext* eCtx, const CMPIResult* eRslt,
    const CMPIObjectPath* eCop);
   static CMPIStatus driveExecQuery
   (CMPIInstanceMI* mi, const CMPIContext* eCtx, const CMPIResult* eRslt,
    const CMPIObjectPath* eCop, const char* language ,const char* query);


   virtual CmpiStatus enumInstanceNames
   (const CmpiContext& ctx, CmpiResult& rslt, const CmpiObjectPath& cop);
   virtual CmpiStatus enumInstances
   (const CmpiContext& ctx, CmpiResult& rslt, const CmpiObjectPath& cop,
    const char* *properties);
   virtual CmpiStatus getInstance
   (const CmpiContext& ctx, CmpiResult& rslt, const CmpiObjectPath& cop,
    const char* *properties);
   virtual CmpiStatus createInstance
   (const CmpiContext& ctx, CmpiResult& rslt, const CmpiObjectPath& cop,
    const CmpiInstance& inst);
   virtual CmpiStatus setInstance
   (const CmpiContext& ctx, CmpiResult& rslt, const CmpiObjectPath& cop,
    const CmpiInstance& inst, const char* *properties);
   virtual CmpiStatus deleteInstance
   (const CmpiContext& ctx, CmpiResult& rslt, const CmpiObjectPath& cop);
   virtual CmpiStatus execQuery
   (const CmpiContext& ctx, CmpiResult& rslt, const CmpiObjectPath& cop,
    const char* language, const char* query);
};

#endif









