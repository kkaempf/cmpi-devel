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
 * Contributors:
 *
 * Description: CMPI Function Arguments Definitions
 *
 */

#ifndef _CmpiArgs_h_
#define _CmpiArgs_h_

#include "cmpidt.h"
#include "cmpift.h"

#include "Linkage.h"
#include "CmpiBaseMI.h"
#include "CmpiObject.h"
#include "CmpiStatus.h"
#include "CmpiObjectPath.h"
#include "CmpiBroker.h"
#include "CmpiBaseMI.h"

/** This class wraps a CIMOM specific input and output arguments
    passed to methodInvocation functions.
*/

class CMPI_PROVIDER_LINKAGE CmpiArgs : public CmpiObject {
   friend class CmpiBroker;
   friend class CmpiMethodMI;
  protected:

   /** Protected constructor used by MIDrivers to encapsulate CMPIArgs.
   */
   CmpiArgs(CMPIArgs* enc);

   /** Gets the encapsulated CMPIArgs.
   */
   CMPIArgs *getEnc() const;

   void *makeArgs(CMPIBroker* mb);
  private:
  public:

   /** Constructor - Empty argument container.
   */
   CmpiArgs();

    /**	getArgCount - Gets the number of arguments
	defined for this argument container.
	@return	Number of arguments in this container.
    */
   unsigned int getArgCount() const;

    /**	getArg - Gets the CmpiData object representing the value
        associated with the argument  name
	@param name argument name.
	@return CmpiData value object associated with the argument.
    */
   CmpiData getArg(const char* name) const;

    /**	getArgument - Gets the CmpiData object defined
	by the input index parameter.
	@param index Index into the argument array.
	@param name Optional output parameter returning the argument name.
	@return CmpiData value object corresponding to the index.
    */
   CmpiData getArg(const int index, CmpiString *name=NULL) const;

    /**	setArg - adds/replaces an argument value defined by the input
	parameter to the container.
	@param name Property name.
	@param data Type and Value to be added.
    */
   void setArg(const char* name, const CmpiData& data);
};

#endif
