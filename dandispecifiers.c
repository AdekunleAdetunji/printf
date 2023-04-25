#include "main.h"
/**
* print_integer - prints an integer to stdout
* @n: The integer to print
* Return: Void
*/
void print_integer(int n)
{
	char j;

	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n / 10)
		print_integer(n / 10);
	j = n % 10 + '0';
	write(1, &j, 1);
}
/**
* char_s - replaces %c, %s, %, flag in code block
* @format: The character string under consideration
* @arg_list: The variadic argument list
* @i: The i value we are iterating with
* @count: The count of the values printed to stdout
* Return: Void values
*/
void char_s(const char *format, va_list arg_list, int *i, int *count)
{
	char per = '%';
	int num;

	switch (format[*i + 1])
	{
		case 'd':
		case 'i':
			num = va_arg(arg_list, int);
			print_integer(num);
			*i += 1;
			break;
		case '%':
			write(1, &per, 1), *i += 1;
			break;
		default:
			write(1, &per, 1);
			write(1, &format[*i + 1], 1);
			*i += 1;
			break;
	}
	*count += 1;
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
		if (format[i + 1] == '%')
		{
			write(1, "%", 1);
			count += 1;
			i += 1;
			continue;
		}
		char_s(format, arg_list, &i, &count);
	}
	va_end(arg_list);
	return (count);
}