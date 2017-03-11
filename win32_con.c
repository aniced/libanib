/* win32_con.c */

HANDLE handle_alternate;
FILE* f_alternate;
WORD old_text_attributes;

HANDLE stdout_handle() {
	return GetStdHandle(STD_OUTPUT_HANDLE);
}

void init_con() {
	handle_alternate = NULL;
	{
		CONSOLE_SCREEN_BUFFER_INFO info;
		GetConsoleScreenBufferInfo(stdout_handle(), &info);
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
	SetConsoleTextAttribute(stdout_handle(), bg << 4 | fg);
}

void con_reset_color() {
	SetConsoleTextAttribute(stdout_handle(), old_text_attributes);
}

void con_set_pos(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(stdout_handle(), coord);
}

void con_alternate() {
	handle_alternate = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
	);
	SetConsoleActiveScreenBuffer(handle_alternate);
	stdout = _fdopen(_open_osfhandle(handle_alternate, _O_TEXT), "w");
}

void con_alternate_exit() {
	CloseHandle(handle_alternate);
	SetConsoleActiveScreenBuffer(handle_stdout);
	handle_active_console = handle_stdout;
}
