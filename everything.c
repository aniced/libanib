/* everything.c */

#define _LIBANIB_EXPORT
#include "anib.h"

/* cross-platform utilities */
#include "error.c"
#include "fncheck.c"

/* platform-specific implementations */
#ifdef _WIN32
	#include "win32_init.c"
	#include "win32_dir.c"
	#include "win32_con.c"
#else
	#include "posix_init.c"
	#include "posix_dir.c"
	#include "posix_con.c"
#endif
