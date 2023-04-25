#include "main.h"

/**
 * convert_to_binary - converts argument to binary
 * @n: unsigned int argument converted
 *
 * Return: void
 */

void convert_to_binary(unsigned int n)
{
	int i;
	int digits[32];
	char j;

	for (i = 0; n > 0; i++)
	{
		digits[i] = n % 2;
		n = n / 2;
	}
	if (i == 0)
	{
		write(1, &"0", 1);
	}
	else
	{
		i -= 1;
		for (; i >= 0; i--)
		{
		j = digits[i] + '0';
		write(1, &j, 1);
		}
	}
	write(1, "\n", 1);
}
/**
 * char_s - replaces b in code block
 * @format: The character string under consideration
 * @arg_list: The variadic argument list
 * @i: The i value we are iterating with
 * @count: The count of the values printed to stdout
 * Return: Void values
 */

void char_s(const char *format, va_list arg_list, int *i, int *count)
{
	unsigned int num1;

	switch (format[*i + 1])
	{
		case 'b':
			num1 = va_arg(arg_list, unsigned int);
			convert_to_binary(num1);
			*i += 1;
			*count += 1;
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
	{
		return (-1);
	}
	va_start(arg_list, format);
	for (i = 0; format[i] > '\0'; i++)
	{
		if (format[i + 1] == '\0')
		{
			return (-1);
		}
		if (format[i] != '%')
		{
			write(1, &format[i], 1), count += 1;
			continue;
		}
		char_s(format, arg_list, &i, &count);
	}
	va_end(arg_list);
	return (count);
}
