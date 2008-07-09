/*
 * $Id$
 *
 * (C) Copyright IBM Corp. 2006, 2008
 *
 * THIS FILE IS PROVIDED UNDER THE TERMS OF THE ECLIPSE PUBLIC LICENSE 
 * ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE 
 * CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
 *
 * You can obtain a current copy of the Eclipse Public License from
 * http://www.opensource.org/licenses/eclipse-1.0.php
 *
 * Author:       Viktor Mihajlovski <mihajlov@de.ibm.com>
 *
 * Interface Type : Common Manageability Programming Interface ( CMPI )
 *
 * Description: Test Provider
 * 
 * Warning: This is nonsense code, just for compile/link tests
 */

#include <cmpidt.h>
#include <cmpift.h>
#include <cmpimacs.h>

#define LOCALCLASSNAME "C_InstanceTest"

static const CMPIBroker * _broker;

CMPIStatus C_InstanceTestCleanup( CMPIInstanceMI * mi, 
				  const CMPIContext * ctx,
				  CMPIBoolean b ) 
{
  CMReturn(CMPI_RC_OK);
}

CMPIStatus C_InstanceTestEnumInstanceNames( CMPIInstanceMI * mi, 
					    const CMPIContext * ctx, 
					    const CMPIResult * rslt, 
					    const CMPIObjectPath * ref) 
{
  CMPIString *s = CMGetClassName(ref,NULL);
  if (CMGetCharPtr(s)) {
    CMReturn(CMPI_RC_OK);
  } else {
    CMReturn(CMPI_RC_ERR_FAILED);
  }
}

CMPIStatus C_InstanceTestEnumInstances( CMPIInstanceMI * mi, 
					const CMPIContext * ctx, 
					const CMPIResult * rslt, 
					const CMPIObjectPath * ref, 
					const char ** properties) 
{
  CMReturn(CMPI_RC_OK);
}

CMPIStatus C_InstanceTestGetInstance( CMPIInstanceMI * mi, 
				      const CMPIContext * ctx, 
				      const CMPIResult * rslt, 
				      const CMPIObjectPath * ref, 
				      const char ** properties) 
{
  CMPIString *s;
  CMPIData d = CMGetKeyAt(ref,0,&s,NULL);
  if (CMIsNullValue(d)) {
    CMReturn(CMPI_RC_OK);
  } else {
    CMReturn(CMPI_RC_ERR_FAILED);
  }
}

CMPIStatus C_InstanceTestCreateInstance( CMPIInstanceMI * mi, 
					 const CMPIContext * ctx, 
					 const CMPIResult * rslt, 
					 const CMPIObjectPath * ref, 
					 const CMPIInstance * ci) 
{
  CMReturn(CMPI_RC_OK);
}

CMPIStatus C_InstanceTestModifyInstance( CMPIInstanceMI * mi, 
					 const CMPIContext * ctx, 
					 const CMPIResult * rslt, 
					 const CMPIObjectPath * ref,
					 const CMPIInstance * ci, 
					 const char **properties) 
{
  CMReturn(CMPI_RC_OK);
}

CMPIStatus C_InstanceTestDeleteInstance( CMPIInstanceMI * mi, 
					 const CMPIContext * ctx, 
					 const CMPIResult * rslt, 
					 const CMPIObjectPath * ref) 
{ 
  CMReturn(CMPI_RC_OK);
}

CMPIStatus C_InstanceTestExecQuery( CMPIInstanceMI * mi, 
				    const CMPIContext * ctx, 
				    const CMPIResult * rslt, 
				    const CMPIObjectPath * ref, 
				    const char * query, 
				    const char * lang) 
{
  CMReturn(CMPI_RC_OK);
}

CMInstanceMIStub( C_InstanceTest,
		  C_InstanceTestProvider,
		  _broker,
		  CMNoHook);
