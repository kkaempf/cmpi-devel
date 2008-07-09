#
# sblim-cmpi-devel.spec
#
# Package spec for cmpi-devel - RedHat/Fedora Flavor
#
# Use this SPEC if building for a RH/Fedora System
# This package is providing the C and C++ headers for CMPI 
# but not the C++ library.
#

BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)

Summary: SBLIM CMPI Provider Development Support
Name: sblim-cmpi-devel
Version: 1.0.5
Release: 0
Group: Systems Management/Base
URL: http://www.sblim.org
License: EPL

Provides: cmpi-devel

Source0: http://prdownloads.sourceforge.net/sblim/%{name}-%{version}.tar.bz2

%Description
This packages provides the C and C++ CMPI header files needed by 
provider developers and can be used standalone. If used for 
C++ provider development it is also necessary to have 
tog-pegasus-devel installed.

%prep

%setup -T -b 0 -n %{name}-%{version}

%build

%configure --disable-library
make %{?_smp_mflags}

%install
rm -rf $RPM_BUILD_ROOT 

make DESTDIR=$RPM_BUILD_ROOT install

%clean
rm -rf $RPM_BUILD_ROOT 

%files
%defattr(-,root,root)
%doc %{_datadir}/doc/%{name}-%{version}
%{_includedir}/cmpi

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig

%changelog
* Wed Jul 09 2008 Tyrel Datwyler <tyreld@us.ibm.com> 1.0.5-0
  - Changed license from CPL to EPL
  
* Thu Feb 09 2006 Viktor Mihajlovski <mihajlov@de.ibm.com> 1.0.4-1
  - Initial RH/Fedora version
