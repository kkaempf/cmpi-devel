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
 * Description: CMPI Datetime Definitions
 *
 */

#ifndef _CmpiDateTime_h_
#define _CmpiDateTime_h_

#include "cmpidt.h"
#include "cmpift.h"

#include "Linkage.h"
#include "CmpiObject.h"
#include "CmpiStatus.h"
#include "CmpiBaseMI.h"


/** This class represents the instance of a CIM DateTime artifact.
*/

class CMPI_PROVIDER_LINKAGE CmpiDateTime : public CmpiObject {

protected:
   void *makeDateTime(CMPIBroker *mb);
   void *makeDateTime(CMPIBroker *mb, const char* utcTime);
   void *makeDateTime(CMPIBroker *mb, const CMPIUint64 binTime,
                                    const CmpiBoolean interval);
private:
public:

   /** Constructor from CMPI type
   */
   CmpiDateTime(const CMPIDateTime* enc);

   /** Constructor - Return current time and date.
   */
   CmpiDateTime();

   CmpiDateTime(const CmpiDateTime& original);

   /** Constructor - Initialize time and date according to &lt;utcTime&gt;.
   @param utcTime Date/Time definition in UTC format
   */
   CmpiDateTime(const char* utcTime);

   /** Constructor - Initialize time and date according to &lt;binTime&gt;.
   @param binTime Date/Time definition in binary format in microsecods
        starting since 00:00:00 GMT, Jan 1,1970.
   @param interval defines Date/Time definition to be an interval value
   */
   CmpiDateTime(const CMPIUint64 binTime, const CmpiBoolean interval);

   /** isInterval - Tests whether time is an interval value.
   @return CmpiBoolean true when time is an interval value.
   */
   CmpiBoolean isInterval() const;


   /** getDateTime - Returns DateTime in binary format.
   @return Uint64 DateTime in binary.
   */
   CMPIUint64 getDateTime() const;

   /** Gets the encapsulated CMPIDateTime.
   */
   CMPIDateTime *getEnc() const;
};

#endif
