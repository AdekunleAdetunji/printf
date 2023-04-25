#include "main.h"

/**
 * char_str - replaces %c, %s, %, flag in code block
 * @format: The character string under consideration
 * @arg_list: The variadic argument list
 * @i: The i value we are iterating with
 * @count: The count of the values printed to stdout
 * Return: Void
 */
void char_str(const char *format, va_list arg_list, int *i, int *count)
{
	char *str, c, per = '%';

	switch (format[*i + 1])
		{
		case 'c':
			c = va_arg(arg_list, int);
			write(1, &c, 1);
			*i += 1;
			break;
		case 's':
			str = va_arg(arg_list, char *);
			if (str)
			{
				write(1, str, strlen(str));
				*i += 1;
				*count += strlen(str) - 1;
			}
			else if (str == NULL)
			{
				write(1, &"(null)", 6);
				*i += 1;
				*count += 5;
			}
			break;
		case '%':
			write(1, &per, 1);
			*i += 1;
			break;
		default:
			write(1, &per, 1);
			break;
		}
	*count += 1;
}

/**
 * int_handle - handles the %d and %i conversion specifier
 * @arg_list: The variable argument list following the function
 * @i: The value we are iterating with
 * @count: The count of characters printed
 * Return: Void
 */
void int_handle(va_list arg_list, int *count, int *i)
{
	int x, arg, absolute, pow = 1;

	arg = va_arg(arg_list, int);
	if (arg < 0)
	{
		putchar('-');
		*count += 1;
	}
	absolute = abs(arg);
	if (absolute < 10)
	{
		putchar('0' + absolute);
		*i += 1;
		*count += 1;
	}
	else if (absolute > 9)
	{
		for (x = 0; (absolute / pow) > 9 ; x++)
		{
			pow *= 10;
		}
		for (x = 0; pow > 0; x++)
		{
			putchar('0' + absolute / pow);
			absolute %= pow;
			pow /= 10;
			*count += 1;
		}
		*i += 1;
	}
}

/**
 * _printf - print the output of a formatted string
 * @format: The format string
 * Return: The total number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, count = 0;
	va_list arg_list;

	if (format == NULL)
		return (-1);
	va_start(arg_list, format);
	for (i = 0; format[i] > '\0'; i++)
	{
		if (!(format[i] == '%'))
		{
			write(1, &format[i], 1), count += 1;
			continue;
		}
		if (format[i + 1] == '\0')
			return (-1);
		if (format[i + 1] == 'i' || format[i + 1] == 'd')
		{
			int_handle(arg_list, &count, &i);
			continue;
		}
		char_str(format, arg_list, &i, &count);
	}
	va_end(arg_list);
	return (count);
}
