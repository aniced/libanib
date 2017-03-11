/* win32_dir.c */

type_dir* dir_open(const char* glob) {
	type_dir* dir = malloc(sizeof(type_dir));
	dir->first = true;
	dir->handle = FindFirstFileA(glob, &dir->ffd);
	return dir;
}

const char* dir_entry(type_dir* dir) {
	if (dir->first) {
		if (dir->handle == INVALID_HANDLE_VALUE) {
			return NULL;
		} else {
			dir->first = false;
		}
	} else if (!FindNextFile(dir->handle, &dir->ffd)) {
		return NULL;
	}
	dir->first = false;
	// ignore . and ..
	{
		const char* name = dir->ffd.cFileName;
		if (!fncheck(name)) return dir_entry(dir);
		return name;
	}
}

void dir_close(type_dir* dir) {
	FindClose(dir->handle);
	free(dir);
}
