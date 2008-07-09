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
 * Description: CMPI Instance Definitions
 *
 */

#ifndef _CmpiInstance_h_
#define _CmpiInstance_h_

#include "cmpidt.h"
#include "cmpift.h"

#include "Linkage.h"
#include "CmpiObject.h"
#include "CmpiStatus.h"
#include "CmpiObjectPath.h"
#include "CmpiBroker.h"
#include "CmpiData.h"

class CmpiObjectPath;
class CmpiData;

/** This class represents the instance of a CIM class. It is used manipulate
    instances and their parts.
*/

class CMPI_PROVIDER_LINKAGE CmpiInstance : public CmpiObject {
   friend class CmpiBroker;
   friend class CmpiResult;
   friend class CmpiInstanceMI;
   friend class CmpiMethodMI;
   friend class CmpiData;
protected:

   /** Protected constructor used by MIDrivers to encapsulate CMPIInstance.
   */
   CmpiInstance(const CMPIInstance* enc);

   /** Gets the encapsulated CMPIInstance.
   */
   CMPIInstance *getEnc() const;

private:

   /** Constructor - Should not be called
   */
   CmpiInstance();

   /** Internal make function
   */
   void *makeInstance(CMPIBroker *mb, const CmpiObjectPath& cop);

   CmpiBoolean doInstanceIsA(CMPIBroker *mb, const char *className);

public:
   /** Constructor - Creates an Instance object with the classname
   from the input parameter.
   @param op defining classname and namespace
   @return The new Instance object
   */
   CmpiInstance(const CmpiObjectPath& op);

   /** instanceIsA - Tests whether this CIM Instance is of type &lt;className&gt;.
   @param className CIM classname to be tested for.
   @return True or False
   */
   CmpiBoolean instanceIsA(const char *className);

   /** getPropertyCount - Gets the number of Properties
   defined for this Instance.
   @return Number of Properties of this instance.
   */
   unsigned int getPropertyCount();

   /** getProperty - Gets the CmpiData object representing the value
       associated with the property name
   @param name Property name.
   @return CmpiData value object associated with the property.
   */
   CmpiData getProperty(const char* name) const;

   /** getProperty - Gets the CmpiData object defined
   by the input index parameter.
   @param index Index into the Property array.
   @param name Optional output parameter returning the property name.
   @return CmpiData value object corresponding to the index.
   */
   CmpiData getProperty(const int index, CmpiString *name=NULL);

   /** setProperty - adds/replaces a property value defined by the input
   parameter to the Instance
   @param name Property name.
   @param data Type and Value to be added.
   */
   void setProperty(const char* name, const CmpiData data);

   /** setPropertyFilter - specifies the list of properties that is accepted
       for setProperty operestions.
   @param properties List of properties
   @param keys List of key properties (required)
   */

   void setPropertyFilter(const char** properties, const char** keys);

   /** getObjectPath - generates an ObjectPath out of the namespace, classname and
   key propeties of this Instance
   @return the generated ObjectPath.
   */
   CmpiObjectPath getObjectPath() const;
};

#endif
