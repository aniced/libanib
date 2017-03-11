/* win32_con.c */

HANDLE handle_stdout;
WORD old_text_attributes;

void init_con() {
	handle_stdout = GetStdHandle(STD_OUTPUT_HANDLE);
	{
		CONSOLE_SCREEN_BUFFER_INFO info;
		GetConsoleScreenBufferInfo(handle_stdout, &info);
		old_text_attributes = info.wAttributes;
	}
}

int windows_console_color(int color) {
	return color = color & 10 | (color & 1) << 2 | (color & 4) >> 2;
}

void con_set_color(int fg, int bg) {
	if (fg < 0) {
		fg = old_text_attributes & 0xf;
	} else {
		fg = windows_console_color(fg);
	}
	if (bg < 0) {
		bg = old_text_attributes & 0xf0;
	} else {
		bg = windows_console_color(bg);
	}
	SetConsoleTextAttribute(handle_stdout, bg << 4 | fg);
}

void con_reset_color() {
	SetConsoleTextAttribute(handle_stdout, old_text_attributes);
}
