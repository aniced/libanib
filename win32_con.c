/* win32_con.c */

HANDLE handle_stdout;
CONSOLE_SCREEN_BUFFER_INFO console_info;
WORD old_text_attributes;

/* private: */

void init_con() {
	handle_stdout = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(handle_stdout, &console_info);
	old_text_attributes = console_info.wAttributes;
}

int windows_console_color(int color) {
	return color = color & 10 | (color & 1) << 2 | (color & 4) >> 2;
}

/* public: */

bool con_is_stdout_tty() {
	return GetFileType(handle_stdout) == FILE_TYPE_CHAR;
}

void con_clear() {
	COORD coord = {0, 0};
	DWORD count = console_info.dwSize.X * console_info.dwSize.Y;
	FillConsoleOutputCharacter(
		handle_stdout, (TCHAR) ' ',
		count, coord, &count
	);
	FillConsoleOutputAttribute(
		handle_stdout, old_text_attributes,
		count, coord, &count
	);
	SetConsoleCursorPosition(handle_stdout, coord);
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

void con_set_pos(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(handle_stdout, coord);
}

void con_alternate() {
	con_clear();
}

void con_alternate_exit() {
	con_clear();
}
