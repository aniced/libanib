/* test.c */
/*
	Compile this separately:
		gcc test.c -o test -L. -lanib
*/

#include "anib.h"

int main(int argc, char** argv) {
	platform_init();
	set_color(4, 9);
	puts("Hello, the colorful world!");
	reset_color();
	return EXIT_SUCCESS;
}
