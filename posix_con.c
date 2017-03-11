/* posix_con.c */

void con_set_color(int fg, int bg) {
	// I expect your terminal to be an ordinary one.
	char sequence[13] = "\e[0;";
	char* p = sequence + 4;
	if (fg > 0 && fg & 8) {
		*p++ = '1';
		*p++ = ';';
	}
	if (fg > 0) {
		*p++ = '3';
		*p++ = '0' + (fg & 7);
		*p++ = ';';
	}
	if (bg > 0) {
		*p++ = '4';
		*p++ = '0' + (bg & 7);
		*p++ = ';';
	}
	*p-- = 0;
	*p = 'm';
	fputs(sequence, stdout);
}

void con_reset_color() {
	printf("\e[0m");
}
