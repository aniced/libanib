/* everything.c */

#define _LIBANIB_EXPORT
#include "anib.h"

/* cross-platform utilities */
#include "fncheck.c"

/* platform-specific implementations */
#ifdef _WIN32
	#include "win32.c"
#else
	#include "posix.c"
#endif
