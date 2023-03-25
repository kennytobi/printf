#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};
/**
 * typedef struct fmt fmt_t - struct up
 * @fmt: the format
 * @fm_t: the function associated
 */
typedef struct fmt fmt_t;
int _printf(const char *format, ...);
int _putchar(char c);
int _puts(const char *s);
#endif
