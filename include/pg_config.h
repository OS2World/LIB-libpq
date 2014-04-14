/* manually compiled pg_config.h for OS/2+EMX libpq build
 *
 * derived from src/include/pg_config.h.in
 * inspired by src/include/pg_config_h.win32
 */

#ifndef pg_config_h_os2emx__
#define pg_config_h_os2emx__

#define PG_VERSION "7.4.8"
#define PG_VERSION_STR "7.4.8 (os2emx)"

#define DEF_PGPORT 5432
#define DEF_PGPORT_STR "5432"

#define ALIGNOF_SHORT	2
#define ALIGNOF_INT	4
#define ALIGNOF_LONG	4
#define ALIGNOF_LONG_LONG_INT	4
#define ALIGNOF_DOUBLE	4
#define MAXIMUM_ALIGNOF	4

#define ACCEPT_TYPE_ARG3	int

/* Define to 1 to build client libraries as thread-safe code.
   (--enable-thread-safety) */
/*#undef ENABLE_THREAD_SAFETY*/

#define HAVE_ATEXIT	1

#define HAVE_CBRT	1

#define HAVE_CRYPT	1
#define HAVE_CRYPT_H	1

#define HAVE_DECL_FDATASYNC	0

#define HAVE_DECL_SNPRINTF	1
#define HAVE_SNPRINTF	1
#define HAVE_DECL_VSNPRINTF	1
#define HAVE_VSNPRINTF	1

#define HAVE_DLOPEN	1

#define HAVE_ENDIAN_H	1

#define HAVE_FCVT	1

/* Define to 1 if fseeko (and presumably ftello) exists and is declared. */
/*#undef HAVE_FSEEKO*/

#define HAVE_GETHOSTBYNAME_R	1
#define HAVE_GETHOSTNAME	1

#define HAVE_GETOPT	1
#define HAVE_GETOPT_H	1
#define HAVE_GETOPT_LONG	1

#define HAVE_INT_TIMEZONE	1

#define HAVE_ISINF	1

#define HAVE_LIBCRYPTO	1

#define HAVE_LIBDL	1

#define HAVE_LIBM	1

#define HAVE_LIBREADLINE	1

#define HAVE_LIBSOCKET	1

#define HAVE_LIBSSL	1

#define HAVE_LIBZ	1

#define HAVE_LL_CONSTANTS	1

#define HAVE_LONG_LONG_INT_64	1
#define INT64_FORMAT 	"%lld"

#define HAVE_MEMMOVE	1
#define HAVE_MEMORY_H	1

#define HAVE_NETINET_IN_H	1
#define HAVE_NETINET_TCP_H	1

#define HAVE_PWD_H	1

#define HAVE_RANDOM	1
#define HAVE_SRANDOM	1

#define HAVE_READLINE_HISTORY_H	1
#define HAVE_READLINE_READLINE_H	1
#define HAVE_REPLACE_HISTORY_ENTRY	1
#define HAVE_RL_COMPLETION_APPEND_CHARACTER	1
#define HAVE_RL_FILENAME_COMPLETION_FUNCTION	1

#define HAVE_RINT	1

#define HAVE_SIGPROCMASK	1
#define HAVE_SIGSETJMP	1
#define HAVE_SIG_ATOMIC_T	1

/* Define to 1 if you have spinlocks. */
#undef HAVE_SPINLOCKS

#define HAVE_STDLIB_H	1

#define HAVE_STRCASECMP 1
#define	strcasecmp(a,b)	stricmp(a,b)
#define	strncasecmp(a,b,c)	strnicmp(a,b,c)

#define HAVE_STRDUP	1

#define HAVE_STRERROR	1

#define HAVE_STRINGIZE	1

#define HAVE_STRINGS_H	1
#define HAVE_STRING_H	1
#define HAVE_STRTOL	1
#define HAVE_STRTOUL	1

#define HAVE_STRTOLL	1
#define strtoll(a,b,c)	_strtoll(a,b,c)
#define HAVE_STRTOULL	1
#define strtoull(a,b,c)	_strtoull(a,b,c)

#define HAVE_STRUCT_SOCKADDR_UN	1

#define HAVE_SYSCONF	1
#define HAVE_SYSLOG	1

#define HAVE_SYS_IPC_H	1
#define HAVE_SYS_SEM_H	1
#define HAVE_SYS_SHM_H	1

#define HAVE_SYS_SELECT_H	1
#define HAVE_SYS_SOCKET_H	1

#define HAVE_SYS_STAT_H	1

#define HAVE_SYS_TYPES_H	1

#define HAVE_SYS_UN_H	1

#define HAVE_TERMIOS_H	1

#define HAVE_TZNAME	1

#define HAVE_UNION_SEMUN	1

#define HAVE_UNISTD_H	1

#define HAVE_UNIX_SOCKETS	1

#define HAVE_UTIME	1
#define HAVE_UTIMES	1
#define HAVE_UTIME_H	1

#define HAVE_WAITPID	1

/* Define if non *_r libc functions are not thread safe */
#undef NEED_REENTRANT_FUNCS

/* Define to the address where bug reports for this package should be sent. */
#undef PACKAGE_BUGREPORT

/* Define to the full name of this package. */
#undef PACKAGE_NAME

/* Define to the full name and version of this package. */
#undef PACKAGE_STRING

/* Define to the one symbol short name of this package. */
#undef PACKAGE_TARNAME

/* Define to the version of this package. */
#undef PACKAGE_VERSION

#define SIZEOF_UNSIGNED_LONG	4

/* Define to 1 if you have the ANSI C header files. */
#undef STDC_HEADERS

/* Define to 1 to build with assertion checks. (--enable-cassert) */
#define USE_ASSERT_CHECKING	1

#define USE_INTEGER_DATETIMES	1

/* Define to 1 to build with Rendezvous support. (--with-rendezvous) */
#undef USE_RENDEZVOUS

#define USE_SSL	1

#define USE_SYSV_SEMAPHORES	1
#define USE_SYSV_SHARED_MEMORY	1

/* Define to 1 to make fseeko visible on some hosts (e.g. glibc 2.2). */
#undef _LARGEFILE_SOURCE

/* Define for large files, on AIX-style hosts. */
#undef _LARGE_FILES

#endif /* pg_config_h_os2emx__ */
