Multithread compatible port of PostgreSQL libpq library, v7.4.8
---------------------------------------------------------------

Vincenzo Venuto maintains a port of PostgreSQL at 
http://www.ecomstation.it/postgres/.

Unfortunately, Vincenzo's port is distributed with libpq libraries and
DLLs that are linkable only with single-threaded EMX applications.

More recently, Lorne Sunley has released a port of PostgreSQL v8, using
the Innotek gcc toolchain and runtime support.

Because I wanted to build PostgreSQL interface modules for my EMX based
port of Python, which is fully multithread capable, I need to build
multithread & EMX compatible versions of libpq.


Dependencies

The DLL (pq74.dll) has been built staticly linked with OpenSSL 0.9.7g,
built from the OpenSSL 0.9.7g source using the included OS/2 support.
I elected to do this for 2 reasons:
- it minimises the risk of clashing with the OpenSSL DLLs included in
  Vincenzo's port (which are single-threaded);
- it minimises (but doesn't eliminate) risks associated with distribution
  of cryptographic code (which is part of OpenSSL).

Please note that I cannot test this, as I don't have an SSL configured
PostgreSQL server.  I would appreciate reports on success or failure of
this package with SSL connections to PostgreSQL servers.

The DLL has also been staticly linked with the crypt library from
Anthony Curtis' EMX pthreads emulation package, which was derived from
FreeBSD 2.2.

The static libraries depend on linkage against a crypt library, either
the one I used or the GNU UFC library, and the ssl and crypto libraries
from OpenSSL 0.9.7 (it may work against 0.9.6 but I gather there were
header changes which may cause problems).

The DLL is dependant on the multithreaded EMX C runtime library
(EMXLIBCM.DLL), and the static libraries must also be linked against
the EMX C library (either static or DLL).  Note that if the application 
linked to the DLL is staticly linked to the EMX C library, the DLL will 
have problems as the C runtime environment (as far as the DLL is 
concerned) doesn't get properly initialised - in particular environment 
variable access doesn't work.

This package cannot be used with applications that aren't linked against
the EMX C library, as the sockets support doesn't get properly initialised.
If you need such support, I have a separate package which contains a
fully standalone libpq DLL package available from my website.


Build notes

This build should support the default connection via OS/2 sockets if
the PostgreSQL server is running on the same machine as the client.

No source changes to the distributed PostgreSQL sources were required, 
except to several C header files (to add the definitions necessary for 
OS/2 support) and a file containing path manipulation code.

This release contains only the PostgreSQL header files required for
building client applications requiring the libpq library.  Although
many PostgreSQL header files have remained the same as those in Vincenzo's
v7.3.2 package, a number have changed significantly.  As this package
is only intended for developers of libpq clients, I have not included
headers not required for building libpq client applications to avoid
version conflicts in other contexts.  The header files in this package
__SHOULD__NOT__ be copied over the header files in Vincenzo's package.

The client library should usable against PostgreSQL servers running on
any platform in addition to Vincenzo's port running on an OS/2 server,
possible version mismatches notwithstanding (though PostgreSQL is
pretty good with forward and backward client-server version compatibility).

The library test programs are included, but you must have a server
running on the same machine with a database called template1, with
access granted to the user specified by the USER environment variable.

An additional test - testlo, in both static and dynamicly linked versions - 
is included to test correct operation of the BLOB import/export code in
libpq in response to a bug identified by Nathan Woodruff (thanks Nathan!).
Please refer to the comments in src/testlo.c for usage.


Contents

This archive contains the following subdirectories and files:

README.1st  (this file)
bin/
    testlibpq.exe
    testlibpq_dll.exe
    testlo.exe
    testlo_dll.exe
dll/
    pq74.dll    {libpq DLL, staticly linked with OpenSSL 0.9.7d}
include/
    {a minimal set of PostgreSQL header files to support compiling and
     linking against libpq with the EMX toolchain}
lib/
    pq74.a      {a.out static library}
    pq74.lib    {OMF static library}
    pq74_d.a    {a.out import library for pq74.dll}
    pq74_d.lib  {OMF import library for pq74.dll}
src/
    libpq-7.4.8.patch {patch to add OS/2 sockets support and
                       Makefile/.DEF file)}
    testlo.c    {BLOB import/export test}


Installation

Users with applications dependant on pq74.dll, should copy pq74.dll
to a location in the LIBPATH, or set via BEGINLIBPATH or ENDLIBPATH.

Developers, additionally, should copy the contents of the include and
lib subdirectories to locations appropriate to their development
environment.

If you wish to do this, unpack the PostgreSQL v7.4.8 source, and 
apply libpq-7.4.8.patch to the unpacked PostgreSQL source tree.
Change into the src/interfaces/libpq subdirectory, then
  make -f Makefile.os2emx

If you wish to build with USE_SSL defined (in src/include/pg_config.h, 
enabled as distributed) you will need to obtain, unpack, configure 
and build OpenSSL prior to attempting to build libpq.


Support

I can't provide much in the way of support for developing PostgreSQL
applications, however if you have problems that appear to be specific
to this package let me know.

This software is provided 'as-is', without any express or implied warranty.
In no event will the packager be held liable for any damages arising from
the use of the software.


Andrew MacIntyre
andymac@bullseye.apana.org.au or andymac@pcug.org.au
http://www.andymac.org/
August 4, 2005.
