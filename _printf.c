#include "main.h"
#include <stdio.h>
/**
 * _printf - produces output according to a format
 * @format: character string containing zero or more directives
 * Return: number of characters printed (excluding null bytes)
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					putchar(va_arg(args, int));
					count++;
					break;
				case 's':
					count ++ printf("%s", va_arg(args, char *));
					break;
				case '%':
					putchar('%');
					count++;
					break;
				default:
					putchar('%');
					putchar(format[i]);
					count += 2;
					break;
			}
		}
		else
		{
			putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
