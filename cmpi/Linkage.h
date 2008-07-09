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
 * Contributors:  Viktor Mihajlovski <mihajlov@de.ibm.com>
 *
 * Description: CMPI C++ Wrapper Linkage Helper
 *
 */

#ifdef CMPI_PLATFORM_WIN32_IX86_MSVC
#ifdef CMPI_WRAPPER_IMPL
#define CMPI_PROVIDER_LINKAGE __declspec(dllexport)
#else
#define CMPI_PROVIDER_LINKAGE __declspec(dllimport)
#endif
#else
#define CMPI_PROVIDER_LINKAGE 
#endif

