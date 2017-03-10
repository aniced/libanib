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
	extern "C" {
	#endif

	#ifdef __cplusplus
	}
	#endif
#endif
