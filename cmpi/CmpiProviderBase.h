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
 * Description: CMPI ProviderBase Helper Definitions
 *
 */

#ifndef _CmpiProviderBase_h_
#define _CmpiProviderBase_h_

#include "Linkage.h"

class CmpiBaseMI;

class CMPI_PROVIDER_LINKAGE CmpiProviderBase {
public:
   CmpiProviderBase();
   ~CmpiProviderBase();
   CmpiBaseMI* getBaseMI();
   void setBaseMI(CmpiBaseMI* aBaseMI);
   void incUseCount();
   int decUseCount();
private:
   friend class CmpiArgs;
   friend class CmpiArray;
   friend class CmpiDateTime;
   friend class CmpiInstance;
   friend class CmpiObject;
   friend class CmpiObjectPath;
   friend class CmpiStatus;
   friend class CmpiString;
   friend class CmpiBaseMI;
   // per provider CmpiBaseMI
   CmpiBaseMI* baseMI;
   int useCount;
   // only for usage inside CMPI CPP library
   static CMPIBroker *getBroker();
   static void setBroker(const CMPIBroker *mb);
};

#endif


