#include <stdarg.h>
#include "main.h"

/**
 * _strlen_recursion - find the length of a string
 * @s: string to compute the length of
 *
 * Return: length of the string
 */

int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	else
		return (1 + _strlen_recursion(s + 1));
}

/**
 * _printf - output according to a format
 * @format: a provided character string
 * Return: characters excluding null byte
 */

int _printf(const char *format, ...)
{
	va_list args;
	char c, *s;
	int len, i;

	va_start(args, format);
	for (i = 0; format != NULL && format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				c = va_arg(args, int);
				_putchar(c);
			}
			else if (format[i] == 's')
			{
				s = va_arg(args, char *);
				for (i = 0; s[i] != '\0'; i++)
				{
					_putchar(s[i]);
				}
				len = _strlen_recursion(s);
				i += len - 1;
			}
			else if (format[i] == '%')
			{
				_putchar('%');
			}
			else
			{
				_putchar(format[i]);
			}
		}
		else
			_putchar(format[i]);
	}
	va_end(args);
	return (i);
}
