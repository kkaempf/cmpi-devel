/*
 * $Id$
 *
 * (C) Copyright IBM Corp. 2006
 *
 * THIS FILE IS PROVIDED UNDER THE TERMS OF THE COMMON PUBLIC LICENSE 
 * ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE 
 * CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
 *
 * You can obtain a current copy of the Common Public License from
 * http://www.opensource.org/licenses/cpl1.0.php
 *
 * Author:       Viktor Mihajlovski <mihajlov@de.ibm.com>
 *
 * Interface Type : Common Manageability Programming Interface ( CMPI )
 *
 * Description: Test Provider
 * 
 * Warning: This is nonsense code, just for compile/link tests
 */

#include <CmpiInstanceMI.h>

class CXX_InstanceTestProviderClass : public CmpiInstanceMI
{
public:
  CXX_InstanceTestProviderClass(const CmpiBroker &b, const CmpiContext &c); 
};

CXX_InstanceTestProviderClass::CXX_InstanceTestProviderClass(const CmpiBroker &b, 
							     const CmpiContext &c)
  : CmpiBaseMI(b,c), CmpiInstanceMI(b,c)
{
}

CMProviderBase(CXX_InstanceTestProvider);

CMInstanceMIFactory(CXX_InstanceTestProviderClass,CXX_InstanceTestProvider);

