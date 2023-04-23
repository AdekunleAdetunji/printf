#include "main.h"

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
		return (-1);
	va_start(arg_list, format);
	for (i = 0; !(format[i] == '\0'); i++)
	{
		if (!(format[i] == '%'))
		{
			write(1, &format[i], 1), count += 1;
			continue;
		}
		switch (format[i + 1])
		{
			case 'c':
				c = va_arg(arg_list, int), write(1, &c, 1);
				i += 1;
				break;
			case 's':
				str = va_arg(arg_list, char *);
				if (str)
				{
					write(1, str, strlen(str));
					i += 1;
				}
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
}
