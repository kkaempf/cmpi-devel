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
 * Description: CMPI Property MI Definitions
 *
 */

#ifndef _CmpiPropertyMI_h_
#define _CmpiPropertyMI_h_

#include <iostream>

#include "cmpidt.h"
#include "cmpift.h"

#include "Linkage.h"
#include "CmpiBaseMI.h"
#include "CmpiStatus.h"
#include "CmpiObjectPath.h"
#include "CmpiResult.h"
#include "CmpiContext.h"
#include "CmpiArgs.h"


class CMPI_PROVIDER_LINKAGE CmpiPropertyMI : virtual public CmpiBaseMI {
public:
   CmpiPropertyMI(const CmpiBroker &mbp, const CmpiContext& ctx);

   static CMPIStatus driveSetProperty
   (CMPIPropertyMI* mi, CMPIContext* eCtx, CMPIResult* eRslt,
    CMPIObjectPath* eOp, char* name, CMPIData data);
   static CMPIStatus driveGetProperty
   (CMPIPropertyMI* mi, CMPIContext* eCtx, CMPIResult* eRslt,
    CMPIObjectPath* eOp, char* name);

   virtual CmpiStatus setProperty
   (const CmpiContext& ctx, CmpiResult& rslt,
    const CmpiObjectPath& op, const char* name, const CmpiData& data);
   virtual CmpiStatus getProperty
   (const CmpiContext& ctx, CmpiResult& rslt,
    const CmpiObjectPath& op, const char* name);
};

#endif

