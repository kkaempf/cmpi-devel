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
 * Description: CMPI Association MI Definitions
 *
 */

#ifndef _CmpiAssociationMI_h_
#define _CmpiAssociationMI_h_

#include <iostream>

#include "cmpidt.h"
#include "cmpift.h"

#include "Linkage.h"
#include "CmpiBaseMI.h"
#include "CmpiStatus.h"
#include "CmpiObjectPath.h"
#include "CmpiResult.h"
#include "CmpiContext.h"


class CMPI_PROVIDER_LINKAGE CmpiAssociationMI : virtual public CmpiBaseMI {
public:
   CmpiAssociationMI(const CmpiBroker &mbp, const CmpiContext& ctx);

   static CMPIStatus driveAssociators
   (CMPIAssociationMI* mi, const CMPIContext* eCtx, const CMPIResult* eRslt,
    const CMPIObjectPath* eOp, const char* asscClass, const char* resultClass,
    const char* role, const char* resultRole, const char** properties);
   static CMPIStatus driveAssociatorNames
   (CMPIAssociationMI* mi, const CMPIContext* eCtx, const CMPIResult* eRslt,
    const CMPIObjectPath* eOp, const char* assocClass, const char* resultClass,
    const char* role, const char* resultRole);
   static CMPIStatus driveReferences
   (CMPIAssociationMI* mi, const CMPIContext* eCtx, const CMPIResult* eRslt,
    const CMPIObjectPath* eOp, const char* resultClass, const char* role ,
    const char** properties);
   static CMPIStatus driveReferenceNames
   (CMPIAssociationMI*, const CMPIContext* eCtx, const CMPIResult* eRslt,
    const CMPIObjectPath* eOp, const char* resultClass, const char* role);

   virtual CmpiStatus associators
   (const CmpiContext& ctx, CmpiResult& rslt,
    const CmpiObjectPath& op, const char* asscClass, const char* resultClass,
    const char* role, const char* resultRole, const char** properties);
   virtual CmpiStatus associatorNames
   (const CmpiContext& ctx, CmpiResult& rslt,
    const CmpiObjectPath& op, const char* assocClass, const char* resultClass,
    const char* role, const char* resultRole);
   virtual CmpiStatus references
   (const CmpiContext& ctx, CmpiResult& rslt,
    const CmpiObjectPath& op, const char* resultClass, const char* role ,
    const char** properties);
   virtual CmpiStatus referenceNames
   (const CmpiContext& ctx, CmpiResult& rslt,
    const CmpiObjectPath& op, const char* resultClass, const char* role);
};

#endif

