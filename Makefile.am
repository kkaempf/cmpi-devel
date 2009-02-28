# $Id$

AM_CFLAGS=-Wall
AM_CXXFLAGS=-Wall
AM_CPPFLAGS=-I$(srcdir)/cmpi \
            @SBLIM_CMPI_PLATFORM@

docdir=$(datadir)/doc/$(PACKAGE)-$(VERSION)

if INSTALL_LIBRARY
lib_LTLIBRARIES=libcmpiCppImpl.la
else
noinst_LTLIBRARIES=libcmpiCppImpl.la
endif

nobase_include_HEADERS=cmpi/CmpiArgs.h cmpi/CmpiBroker.h cmpi/cmpidt.h \
	cmpi/CmpiInstanceMI.h cmpi/cmpios.h cmpi/CmpiStatus.h \
	cmpi/CmpiArray.h cmpi/CmpiCharData.h cmpi/CmpiEnumeration.h \
	cmpi/cmpimacs.h cmpi/CmpiPropertyMI.h cmpi/CmpiString.h \
	cmpi/CmpiAssociationMI.h cmpi/CmpiContext.h cmpi/cmpift.h \
	cmpi/CmpiMethodMI.h cmpi/CmpiProviderBase.h cmpi/Linkage.h \
	cmpi/CmpiBaseMI.h cmpi/CmpiData.h cmpi/CmpiIndicationMI.h \
	cmpi/CmpiObject.h cmpi/CmpiResult.h cmpi/CmpiBooleanData.h \
	cmpi/CmpiDateTime.h cmpi/CmpiInstance.h cmpi/CmpiObjectPath.h \
	cmpi/CmpiSelectExp.h

libcmpiCppImpl_la_SOURCES=CmpiImpl.cpp

check_LTLIBRARIES=libc_instance.la libcxx_instance.la
check_PROGRAMS=c_instance_link cxx_instance_link

libc_instance_la_SOURCES=test/c_instance.c

libcxx_instance_la_SOURCES=test/cxx_instance.cxx

c_instance_link_SOURCES=test/c_instance_link.c
c_instance_link_LDADD=-lc_instance
c_instance_link_DEPENDENCIES=libc_instance.la

cxx_instance_link_SOURCES=test/cxx_instance_link.cxx
cxx_instance_link_LDADD=-lcxx_instance -lcmpiCppImpl
cxx_instance_link_DEPENDENCIES=libc_instance.la libcmpiCppImpl.la

TESTS=$(check_PROGRAMS)

EXTRA_DIST=$(PACKAGE).spec license.html

install-data-local: 
	test -d $(DESTDIR)$(docdir) || $(mkdir_p) $(DESTDIR)$(docdir)
	$(INSTALL_DATA) $(srcdir)/README $(srcdir)/AUTHORS $(srcdir)/COPYING $(DESTDIR)$(docdir)


uninstall-local:
	rm -rf $(DESTDIR)$(docdir)
