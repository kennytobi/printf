#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int num_args = 0, num_printed = 0, arg;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'd':
				case 'i':
					num_args++;
					arg = va_arg(args, int);
					num_printed += printf("%d", arg);
					break;
				default:
					num_printed += printf("%%%c", *format);
			}
		}
		else
		{
			putchar(*format);
			num_printed++;
		}
		format++;
	}
	va_end(args);
	return (num_printed);
}
