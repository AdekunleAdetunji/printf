<<<<<<< HEAD
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

/**
 * _printf - print the output of a formatted string
 * @format: The format string
 * Return: The total number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, count = 0, c;
	char per = '%', *str;
	va_list arg_list;

	if (format == NULL)
		return (count);
	va_start(arg_list, format);
	for (i = 0; format[i] > '\0'; i++)
	{
		if (!(format[i] == '%'))
		{
			write(1, &format[i], 1), count += 1;
			continue;
		}
		switch(format[i + 1])
		{
		case 'c':
			c = va_arg(arg_list, int), write(1, &c, 1);
			i += 1;
			break;
		case 's':
			str = va_arg(arg_list, char *);
			if (str)
				write(1, str, strlen(str));
			i += 1;
			break;
		case '%':
			write(1, &per, 1), i += 1;
			break;
		default:
			write(1, &per, 1);
			break;
		}
		count += 1;
	}
	return (count);
=======
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
	if (format == NULL)
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
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
				_write_char('%');
			else
				_write_char(format[i]);
		}
		else
			_write_char(format[i]);
	}
	va_end(args);
	return (i);
>>>>>>> 5a2092d30b9d9895170f4444be58111966c3ca5c
}
