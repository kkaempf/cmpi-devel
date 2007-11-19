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
 * Description: CMPI Mgmt Broker Definitions
 *
 */

#ifndef _CmpiBroker_h_
#define _CmpiBroker_h_

#include "cmpidt.h"
#include "cmpift.h"

class CmpiInstance;
class CmpiObject;
class CmpiEnumeration;
class CmpiArgs;

#include "Linkage.h"
#include "CmpiObject.h"
#include "CmpiString.h"
#include "CmpiInstance.h"
#include "CmpiContext.h"
#include "CmpiObjectPath.h"
#include "CmpiBaseMI.h"
#include "CmpiEnumeration.h"

/** This class encapsulates services provided by the CIM Object Manager
*/

class CMPI_PROVIDER_LINKAGE CmpiBroker : public CmpiObject {
public:
   /** constructor to encapsulate CMPIBroker.
   */
   CmpiBroker(CMPIBroker* b);

   /** getEnc - Gets the encapsulated CMPIBroker.
   */
   CMPIBroker *getEnc() const;

   /** This function prepares the CMPI run time system to accept
         a thread that will be using CMPI services. The returned
   CMPIContext object must be used by the subsequent attachThread()
   and detachThread() invocations.
   @param ctx Old Context object
   @return New Context object to be used by thread to be attached.
   */
   CmpiContext prepareAttachThread
      (const CmpiContext& ctx);

   /** This function informs the CMPI run time system that the current
      thread with Context will begin using CMPI services.
   @param ctx Context object
   */
   void attachThread
      (const CmpiContext& ctx);

   /** This function informs the CMPI run time system that the current thread
      will not be using CMPI services anymore. The Context object will be
   freed during this operation.
   @param ctx Context object
   */
   void detachThread
     (const CmpiContext& ctx);

   // class 0 services

   /** This function requests delivery of an Indication. The CIMOM will
      locate pertinent subscribers and notify them about the event.
   @param ctx Context object
   @param ns Namespace
   @param ind Indication Instance
   */
   void deliverIndication
      (const CmpiContext& ctx, const char* ns,const CmpiInstance& ind);

   /** Enumerate Instance Names of the class (and subclasses) defined by &lt;op&gt;.
   @param ctx Context object
   @param op ObjectPath containing namespace and classname components.
   @return Enumeration of ObjectPathes.
   */
   CmpiEnumeration enumInstanceNames
      (const CmpiContext& ctx, const CmpiObjectPath& op);

   /** Get Instance using &lt;op&gt; as reference. Instance structure can be
      controled using the CMPIInvocationFlags entry in &lt;ctx&gt;.
   @param ctx Context object
   @param op ObjectPath containing namespace, classname and key components.
   @param properties If not NULL, the members of the array define one or more Property
   names. Each returned Object MUST NOT include elements for any Properties
   missing from this list
   @return The Instance.
   */
   CmpiInstance getInstance
      (const CmpiContext& ctx, const CmpiObjectPath& op,
       const char** properties);

   /** Create Instance from &lt;inst&gt; using &lt;op&gt; as reference.
   @param ctx Context object
   @param op ObjectPath containing namespace, classname and key components.
   @param inst Complete instance.
   @return The assigned instance reference.
   */
   CmpiObjectPath createInstance
      (const CmpiContext& ctx, const CmpiObjectPath& op,
       const CmpiInstance& inst);

   /** Replace an existing Instance from &lt;inst&gt; using &lt;op&gt; as reference.
   @param ctx Context object
   @param op ObjectPath containing namespace, classname and key components.
   @param inst Complete instance.
   */
   void setInstance
      (const CmpiContext& ctx, const CmpiObjectPath& op,
       const CmpiInstance& inst, const char** properties);

   /** Delete an existing Instance using &lt;op&gt; as reference.
   @param ctx Context object
   @param op ObjectPath containing namespace, classname and key components.
   */
   void deleteInstance
      (const CmpiContext& ctx, const CmpiObjectPath& op);

   /** Query the enumeration of instances of the class (and subclasses) defined
      by &lt;op&gt; using &lt;query&gt; expression.
   @param ctx Context object
   @param op ObjectPath containing namespace and classname components.
   @param query Query expression
   @param lang Query Language
   @return Resulting eumeration of Instances.
   */
   CmpiEnumeration execQuery
      (const CmpiContext& ctx, const CmpiObjectPath& op,
       const char* query, const char* lang);

   /** Enumerate Instances of the class (and subclasses) defined by &lt;op&gt;.
      Instance structure and inheritance scope can be controled using the
   CMPIInvocationFlags entry in &lt;ctx&gt;.
   @param ctx Context object
   @param op ObjectPath containing namespace and classname components.
   @param properties If not NULL, the members of the array define one or more Property
   names. Each returned Object MUST NOT include elements for any Properties
   missing from this list
   @return Enumeration of Instances.
   */
   CmpiEnumeration enumInstances
      (const CmpiContext& ctx, const CmpiObjectPath& op,
       const char** properties);

   /** Enumerate instances associated with the Instance defined by the &lt;op&gt;.
   @param ctx Context object
   @param op Source ObjectPath containing namespace, classname and key components.
   @param assocClass If not NULL, MUST be a valid Association Class name.
   It acts as a filter on the returned set of Objects by mandating that
   each returned Object MUST be associated to the source Object via an
   Instance of this Class or one of its subclasses.
   @param resultClass If not NULL, MUST be a valid Class name.
   It acts as a filter on the returned set of Objects by mandating that
   each returned Object MUST be either an Instance of this Class (or one
   of its subclasses).
   @param role If not NULL, MUST be a valid Property name.
   It acts as a filter on the returned set of Objects by mandating
   that each returned Object MUST be associated to the source Object
   via an Association in which the source Object plays the specified role
   (i.e. the name of the Property in the Association Class that refers
   to the source Object MUST match the value of this parameter).
   @param resultRole If not NULL, MUST be a valid Property name.
   It acts as a filter on the returned set of Objects by mandating
   that each returned Object MUST be associated to the source Object
   via an Association in which the returned Object plays the specified role
   (i.e. the name of the Property in the Association Class that refers to
   the returned Object MUST match the value of this parameter).
   @param properties If not NULL, the members of the array define one or more Property
   names. Each returned Object MUST NOT include elements for any Properties
   missing from this list
   @return Enumeration of Instances.
   */
   CmpiEnumeration associators
      (const CmpiContext& ctx, const CmpiObjectPath& op,
       const char* assocClass, const char* resultClass,
       const char* role, const char* resultRole,
       const char** properties);

   /** Enumerate ObjectPaths associated with the Instance defined by &lt;op&gt;.
   @param ctx Context object
   @param op Source ObjectPath containing namespace, classname and key components.
   @param assocClass If not NULL, MUST be a valid Association Class name.
   It acts as a filter on the returned set of Objects by mandating that
   each returned Object MUST be associated to the source Object via an
   Instance of this Class or one of its subclasses.
   @param resultClass If not NULL, MUST be a valid Class name.
   It acts as a filter on the returned set of Objects by mandating that
   each returned Object MUST be either an Instance of this Class (or one
   of its subclasses).
   @param role If not NULL, MUST be a valid Property name.
   It acts as a filter on the returned set of Objects by mandating
   that each returned Object MUST be associated to the source Object
   via an Association in which the source Object plays the specified role
   (i.e. the name of the Property in the Association Class that refers
   to the source Object MUST match the value of this parameter).
   @param resultRole If not NULL, MUST be a valid Property name.
   It acts as a filter on the returned set of Objects by mandating
   that each returned Object MUST be associated to the source Object
   via an Association in which the returned Object plays the specified role
   (i.e. the name of the Property in the Association Class that refers to
   the returned Object MUST match the value of this parameter).
   @return Enumeration of ObjectPaths.
   */
   CmpiEnumeration associatorNames
      (const CmpiContext& ctx, const CmpiObjectPath& op,
       const char* assocClass, const char* resultClass,
       const char* role, const char* resultRole);

   /** Enumerates the association instances that refer to the instance defined by
       &lt;op&gt;.
   @param ctx Context object
   @param op Source ObjectPath containing namespace, classname and key components.
   @param resultClass If not NULL, MUST be a valid Class name.
   It acts as a filter on the returned set of Objects by mandating that
   each returned Object MUST be either an Instance of this Class (or one
   of its subclasses).
   @param role If not NULL, MUST be a valid Property name.
   It acts as a filter on the returned set of Objects by mandating
   that each returned Object MUST be associated to the source Object
   via an Association in which the source Object plays the specified role
   (i.e. the name of the Property in the Association Class that refers
   to the source Object MUST match the value of this parameter).
   @param properties If not NULL, the members of the array define one or more Property
   names. Each returned Object MUST NOT include elements for any Properties
   missing from this list
   @return Enumeration of ObjectPaths.
   */
   CmpiEnumeration references
      (const CmpiContext& ctx, const CmpiObjectPath& op,
       const char* resultClass, const char* role,
       const char** properties);

   /** Enumerates the association ObjectPaths that refer to the instance defined by
        &lt;op&gt;.
   @param ctx Context object
   @param op Source ObjectPath containing namespace, classname and key components.
   @param resultClass If not NULL, MUST be a valid Class name.
   It acts as a filter on the returned set of Objects by mandating that
   each returned Object MUST be either an Instance of this Class (or one
   of its subclasses).
   @param role If not NULL, MUST be a valid Property name.
   It acts as a filter on the returned set of Objects by mandating
   that each returned Object MUST be associated to the source Object
   via an Association in which the source Object plays the specified role
   (i.e. the name of the Property in the Association Class that refers
   to the source Object MUST match the value of this parameter).
   @return Enumeration of ObjectPaths.
   */
   CmpiEnumeration referenceNames
      (const CmpiContext& ctx, const CmpiObjectPath& op,
       const char* resultClass, const char* role);

   /** Invoke a named, extrinsic method of an Instance
      defined by the &lt;op&gt; parameter.
   @param ctx Context object
   @param op ObjectPath containing namespace, classname and key components.
   @param method Method name
   @param in Input parameters.
   @param out Output parameters.
   @return Method return value.
   */
   CmpiData invokeMethod
      (const CmpiContext& ctx, const CmpiObjectPath& op,
       const char* method, const CmpiArgs& in, CmpiArgs& out);

   /** Set the named property value of an Instance defined by the &lt;op&gt; parameter.
   @param ctx Context object
   @param op ObjectPath containing namespace, classname and key components.
   @param name Property name
   @param data Property value.
   */
   void setProperty
      (const CmpiContext& ctx, const CmpiObjectPath& op,
       const char* name, const CmpiData& data);

   /** Get the named property value of an Instance defined by the &lt;op&gt; parameter.
   @param ctx Context object
   @param op ObjectPath containing namespace, classname and key components.
   @param name Property name
   @return Property value.
   */
   CmpiData getProperty
      (const CmpiContext& ctx, const CmpiObjectPath& op,
       const char* name);
};

#endif



