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
 * Description: CMPI Method MI Definitions
 *
 */

#ifndef _CmpiMethodMI_h_
#define _CmpiMethodMI_h_

#include <iostream>

#include "cmpidt.h"
#include "cmpift.h"

#include "Linkage.h"
#include "CmpiBaseMI.h"
#include "CmpiStatus.h"
#include "CmpiObjectPath.h"
#include "CmpiResult.h"
#include "CmpiContext.h"
#include "CmpiBroker.h"
#include "CmpiArgs.h"


class CMPI_PROVIDER_LINKAGE CmpiMethodMI : virtual public CmpiBaseMI {
public:
   CmpiMethodMI(const CmpiBroker &mbp, const CmpiContext& ctx);

   static CMPIStatus driveInvokeMethod
   (CMPIMethodMI* mi, CMPIContext* eCtx, CMPIResult* eRslt,
    CMPIObjectPath* eCop, const char* methodName,
    CMPIArgs* eIn, CMPIArgs* eOut);

   virtual CmpiStatus invokeMethod
   (const CmpiContext& ctx, CmpiResult& rslt,
    const CmpiObjectPath& ref, const char* methodName,
    const CmpiArgs& in, CmpiArgs& out);
};

#endif

