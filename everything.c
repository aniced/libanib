/* everything.c */

#define _LIBANIB_EXPORT
#include "anib.h"

/* utilities */
#include "fncheck.c"

/* platform */
#ifdef _WIN32
	#include "win32.c"
#else
	#include "posix.c"
#endif
