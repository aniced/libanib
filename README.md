libanib — Library Aniced β
=======

The bedrock for Aniced console applications.

This library provides some basic platform API wrappers, including functions for these operations:

- directory inquiry
- console coloring

Installation
------------

1. Compile everything.c into a shared library. Any of these will work:

	```shell
	# Windows
	gcc -shared -o libanib.dll everything.c
	cl /LD /Felibanib.dll everything.c

	# POSIX
	gcc -shared -o libanib everything.c
	clang -shared -o libanib everything.c
	```

2. Move libanib.so or libanib.dll to somewhere in your $PATH (or %PATH%).
3. Put anib.h where you put C headers.
