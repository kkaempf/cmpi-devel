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

#include <stddef.h>

extern void * C_InstanceTestProvider_Create_InstanceMI(void*, void*);

int main()
{
  if(C_InstanceTestProvider_Create_InstanceMI(NULL,NULL)) {
    return 0;
  } else {
    return -1;
  }
}
