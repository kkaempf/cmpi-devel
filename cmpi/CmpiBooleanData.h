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
 * Description: CMPI Boolean Data Definitions
 *
 */

#ifndef _CmpiBooleanData_h_
#define _CmpiBooleanData_h_

#include "Linkage.h"
#include "CmpiData.h"

/** This class wraps a CMPIBooleanData value item. BooleanData extraction uses type operators.
      Extraction operations can be appended to a property type retrieval statement
      like this:
 
        CmpiString name = cop.getKey("DeviceID");
 
       Type mismatches will be signalled by exceptions.
*/
class CMPI_PROVIDER_LINKAGE CmpiBooleanData : public CmpiData {
public:

   /** Constructor - boolean as input.
   */
   CmpiBooleanData(CMPIBoolean d);

};

extern CmpiBooleanData CmpiTrue;
extern CmpiBooleanData CmpiFalse;

#endif



