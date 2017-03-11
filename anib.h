/* anib.h */

#if defined(_MSC_VER) || defined(__GNUC__)
	#pragma once
#else
	#warning You are using an unsupported compiler.
#endif

#ifndef _LIBANIB_ANIB_H_INCLUDED
	#define _LIBANIB_ANIB_H_INCLUDED

	#include <stddef.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <stdarg.h>
	#include <string.h>
	#ifdef _MSC_VER
		#define bool int
		#define true 1
		#define false 0
	#else
		#include <stdbool.h>
	#endif

	#ifdef _LIBANIB_EXPORT
		#define EXTERN
	#else
		#ifdef __cplusplus
			#define EXTERN extern "C"
		#else
			#define EXTERN extern
		#endif
	#endif

	#ifdef _WIN32
		#ifdef _LIBANIB_EXPORT
			#define API EXTERN __declspec(dllexport)
		#else
			#define API EXTERN __declspec(dllimport)
		#endif
	#else
		#define API EXTERN
	#endif

	/* platform-specific data structures */
	#ifdef _WIN32
		#include <windows.h>
		typedef struct {
			WIN32_FIND_DATA ffd;
			bool first;
			HANDLE handle;
		} type_dir;
	#else
		#include <unistd.h>
		#include <libgen.h>
		#include <dirent.h>
		#include <fnmatch.h>
		typedef struct {
			DIR* dir;
			char glob_base[FILENAME_MAX];
		} type_dir;
	#endif

	/* initialization */
	API void platform_init(void);

	/* directory operations */
	API type_dir* dir_open(const char* glob);
	API const char* dir_entry(type_dir* dir);
	API void dir_close(type_dir* dir);

	/* console color */
	API void set_color(int fg, int bg);
	API void reset_color(void);


	#undef EXTERN
	#undef API
#endif
