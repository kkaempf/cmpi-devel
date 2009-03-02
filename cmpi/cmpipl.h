/*
 *
 * $Id$
 *
 * (C) Copyright IBM Corp. 2009
 *
 * THIS FILE IS PROVIDED UNDER THE TERMS OF THE ECLIPSE PUBLIC LICENSE
 * ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE
 * CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
 *
 * You can obtain a current copy of the Eclipse Public License from
 * http://www.opensource.org/licenses/eclipse-1.0.txt
 *
 * Author:        Tyrel Datwyler  <tyreld@us.ibm.com>        
 * Contributors:  
 *
 * Description: CMPI Platform Definitions
 *
 */

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* Copyright (c) 2006 The Open Group                                         */
/*                                                                           */
/* Permission is hereby granted, free of charge, to any person obtaining a   */
/* copy of this software (the "Software"), to deal in the Software without   */
/* restriction, including without limitation the rights to use, copy,        */
/* modify, merge, publish, distribute, sublicense, and/or sell copies of     */
/* the Software, and to permit persons to whom the Software is furnished     */
/* to do so, subject to the following conditions:                            */
/*                                                                           */
/* The above copyright notice and this permission notice shall be included   */
/* in all copies or substantial portions of the Software.                    */
/*                                                                           */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS   */
/* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF                */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.    */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY      */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT */
/* OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR  */
/* THE USE OR OTHER DEALINGS IN THE SOFTWARE.                                */
/*                                                                           */
/* ------------------------------------------------------------------------- */

#ifndef _CMPIPL_H_
#  define _CMPIPL_H_

#ifdef SBLIM_PLATFORM_LINUX_GENERIC_GNU
#  define  CMPI_PLATFORM_LINUX_GENERIC_GNU
#endif

#ifdef SBLIM_PLATFORM_HPUX_ACC
#  define CMPI_PLATFORM_HPUX_ACC
#endif

#ifdef SBLIM_PLATFORM_WIN32_IX86_MSVC
#  define CMPI_PLATFORM_WIN32_I86_MSVC
#endif

#ifdef SBLIM_PLATFORM_SOLARIS_SPARC_GNU
#  define CMPI_PLATFORM_SOLARIS_SPARC_GNU
#endif

#ifdef SBLIM_PLATFORM_SOLARIS_SPARC_CC
#  define CMPI_PLATFORM_SOLARIS_SPARC_CC
#endif

#ifdef SBLIM_PLATFORM_AIX_RS_IBMCXX
#  define CMPI_PLATFORM_AIX_RS_IBMCXX
#endif

#ifdef SBLIM_PLATFORM_ZOS_ZSERIES_IBM
#  define CMPI_PLATFOMR_ZOS_ZSERIES_IBM
#endif

#ifdef SBLIM_PLATFORM_TRU64_ALPHA_DECCXX
#  define CMPI_PLATFORM_TRU64_ALPHA_DECCXX
#endif

#ifdef SBLIM_PLATFORM_OS400_ISERIES_IBM
#  define CMPI_PLATFORM_OS400_ISERIES_IBM
#endif

#ifdef SLBIM_PLATFORM_DARWIN_PPC_GNU
#  define CMPI_PLATFORM_DARWIN_PPC_GNU
#endif

#ifdef SBLIM_PLATFORM_VMS_ALPHA_DECCXX
#  define CMPI_PLATFORM_VMS_ALPHA_DECCXX
#endif

#ifdef SBLIM_PLATFORM_VMS_IA64_DECCXX
#  define CMPI_PLATFORM_VMS_IA64_DECCXX
#endif

#endif
