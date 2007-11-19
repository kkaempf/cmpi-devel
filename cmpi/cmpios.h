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
 * Description: CMPI OS Specific Definions
 *
 */

#ifndef _CMPIOS_H_
#define _CMPIOS_H_

#define CMPI_THREAD_RETURN      void*
#define CMPI_THREAD_TYPE        void*
#define CMPI_MUTEX_TYPE         void*
#define CMPI_COND_TYPE          void*

#if defined(CMPI_PLATFORM_WIN32_IX86_MSVC)
   #define CMPI_THREAD_CDECL    __stdcall
   #define CMPI_THREAD_KEY_TYPE unsigned long int

struct timespec {
   long tv_sec;
   long tv_nsec;
};

#elif defined( CMPI_PLATFORM_ZOS_ZSERIES_IBM)

#ifndef __cplusplus
   #define CMPI_THREAD_CDECL
#else
   #define CMPI_THREAD_CDECL    __cdecl
#endif

   #define CMPI_THREAD_KEY_TYPE  pthread_key_t
#else
   #define CMPI_THREAD_CDECL
   #define CMPI_THREAD_KEY_TYPE unsigned long int
#endif


#endif
