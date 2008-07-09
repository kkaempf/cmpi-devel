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
 * Description: CMPI Character Data Definitions
 *
 */

#ifndef _CmpiCharData_h_
#define _CmpiCharData_h_

#include "Linkage.h"
#include "CmpiData.h"


/** This class wraps a CMPICharData value item. CharData extraction uses type conversion operators.
      Extraction operations can be appended to a property type retrieval statement
      like this:
 
        CmpiString name = cop.getKey("DeviceID");
 
       Type mismatches will be signalled by exceptions.
*/
class CMPI_PROVIDER_LINKAGE CmpiCharData : public CmpiData {
public:
   /** Constructor - singed 8 bit as input.
   */
   CmpiCharData(CMPIChar16 d);
};

#endif



