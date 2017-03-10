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

	#ifdef _WIN32
		#ifdef _LIBANIB_EXPORT
			#define API __declspec(dllexport)
		#else
			#define API __declspec(dllimport)
		#endif
	#else
		#define API
	#endif

	#ifdef __cplusplus
		#define X extern "C" {
		X // to deal with a few interesting editors
		#undef X
	#endif

	/* initialization */
	API void platform_init(void);

	/* dir */
	API type_dir* dir_open(const char* glob);
	API const char* dir_entry(type_dir* dir);
	API void dir_close(type_dir* dir);

	/* console color */
	API void set_color(int fg, int bg);
	API void reset_color(void);

	#ifdef __cplusplus
	}
	#endif

	#undef API
#endif
