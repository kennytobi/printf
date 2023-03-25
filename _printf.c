#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: character string containing zero or more directives
 * Return: number of characters printed (excluding null bytes)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, len = 0;
	char *str;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					len += _putchar(va_arg(args, int));
					break;
				case 's':
					str = va_arg(args, char *);
					if (str == NULL)
						str = "(null)";
					len += _puts(str);
					break;
				case '%':
					len += _putchar('%');
					break;
				default:
					len += _putchar('%');
					len += _putchar(format[i]);
					break;
			}
		}
		else
		{
			len += _putchar(format[i]);
		}
	}
	va_end(args);
	return (len);
}
/**
 * _putchar - write the character of c to stdout
 * @c: the character to print
 * Return: on success 1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
