#include "main.h"

/**
 * _write_char - writes a single character to the standard output
 * @c: character to write
 *
 * Return: 1 on success, -1 on failure
 */

int _write_char(char c)
{
	return (write(1, &c, 1));
}

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
	int len, i, j;

	va_start(args, format);
	for (i = 0; format != NULL && format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				c = va_arg(args, int);
				_write_char(c);
			}
			else if (format[i] == 's')
			{
				s = va_arg(args, char *);
				for (j = 0; s[j] != '\0'; j++)
				{
					_write_char(s[j]);
				}
				len = _strlen_recursion(s);
				i += len - 1;
			}
			else if (format[i] == '%')
			{
				_write_char('%');
			}
			else
			{
				_write_char(format[i]);
			}
		}
		else
			_write_char(format[i]);
	}
	va_end(args);
	return (i);
}
