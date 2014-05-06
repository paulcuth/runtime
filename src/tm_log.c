#include "tm.h"
#include <stdio.h>
#include <stdarg.h>

#ifdef COLONY_PC
#include <unistd.h>
void tm_log(char level, const char* string, unsigned length) {
	char linebreak = '\n';
	int r = fwrite(string, 1, length, stdout);
	r = fwrite(&linebreak, 1, 1, stdout);
	(void) r;
}
#endif

#define BUF_SIZE 256

void tm_logf(char level, const char* format, ...) {
	va_list args;
	va_start(args, format);
	char buf[BUF_SIZE];
	int len = vsnprintf(buf, sizeof(buf), format, args);
	if (len > BUF_SIZE) len = BUF_SIZE;
	va_end (args);
	tm_log(level, buf, len);
}
