#include "main.h"

/**
 * char_str - replaces %s, %, %i and %d flag in code block
 * @format: The character string under consideration
 * @arg_list: The variadic argument list
 * @i: The i value we are iterating with
 * @count: The count of the values printed to stdout
 * Return: Void values
 */
void char_str(const char *format, va_list arg_list, int *i, int *count)
{
	char *str, per = '%';
	int num1;

	switch (format[*i + 1])
		{
		case 's':
			str = va_arg(arg_list, char *);
			if (str)
			{
				write(1, str, strlen(str));
				*i += 1;
				*count += strlen(str) - 1; }
			else if (str == NULL)
			{
				write(1, &"(null)", 6);
				*i += 1;
				*count += 5; }
			break;
		case 'i':
		case 'd':
			num1 = va_arg(arg_list, int);
			if (num1 < 0)
				write(1, "-", 1);
			*count += 1;
			num1 = -num1;
			if (num1 / 10)
				char_str(format, arg_list, i, count);
			write(1, (const void *)(intptr_t)((num1 % 10) + '0'), 1);
			*i += 1;
			*count += 1;
			break;
		case '%':
			write(1, &per, 1), *i += 1;
			break;
		default:
			write(1, &per, 1);
			break; }
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
		char_str(format, arg_list, &i, &count);
	}
	va_end(arg_list);
	return (count);
}
