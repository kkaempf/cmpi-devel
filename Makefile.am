# $Id$

docdir=$(datadir)/doc/$(PACKAGE)-$(VERSION)

lib_LTLIBRARIES=libcmpiCppImpl.la

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
libcmpiCppImpl_la_CPPFLAGS=-Wall -I$(srcdir)/cmpi

EXTRA_DIST=$(PACKAGE).spec

install-data-local: 
	test -d $(DESTDIR)$(docdir) || $(mkdir_p) $(DESTDIR)$(docdir)
	$(INSTALL_DATA) $(srcdir)/README $(srcdir)/AUTHORS $(srcdir)/COPYING $(DESTDIR)$(docdir)


uninstall-local:
	rm -rf $(DESTDIR)$(docdir)
