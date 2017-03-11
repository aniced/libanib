/* error.c */

/* Usage:
	error("sqrt()", "calculating square root of %f", x);
	error(NULL, "unknown error made by me");
*/
void error(const char* function, const char* format, ...) {
	va_list ap;
	va_start(ap, format);
	if (con_is_stdout_tty()) {
		con_set_color(15, 1);
		printf(" Error ");
		con_reset_color();
	} else {
		printf("[Error]");
	}
	printf("\nMessage: ");
	vprintf(format, ap);
	putchar('\n');
	if (function && *function) perror(function);
	va_end(ap);
	exit(EXIT_FAILURE);
}
