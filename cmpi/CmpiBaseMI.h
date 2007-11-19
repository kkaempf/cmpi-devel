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
 * Description: CMPI Base MI Definitions
 *
 */

#ifndef _CmpiBaseMI_h_
#define _CmpiBaseMI_h_

#include <iostream>

#include "cmpidt.h"
#include "cmpift.h"
#include "cmpimacs.h"

#include "Linkage.h"
#include "CmpiProviderBase.h"

class CmpiBroker;
class CmpiContext;
class CmpiStatus;

class CMPI_PROVIDER_LINKAGE CmpiBaseMI {
public:
   virtual ~CmpiBaseMI();

   CmpiBaseMI(const CmpiBroker &mbp, const CmpiContext& ctx);

   void setProviderBase(CmpiProviderBase* base);
   CmpiProviderBase* getProviderBase();

   static CMPIStatus driveBaseCleanup(void* mi, const CMPIContext* eCtx, CMPIBoolean b);

   virtual CmpiStatus initialize(const CmpiContext& ctx);
   virtual CmpiStatus cleanup(CmpiContext& ctx);
   virtual int isUnloadable() const;

protected:
   CmpiBroker* broker;
private:
   CmpiProviderBase* providerBase;
};

#endif
