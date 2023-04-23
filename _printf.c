#include "main.h"

/**
 * print_buffer - print the contents of a buffer and reset the buffer index
 * @b: the buffer
 * @buff_ind: a pointer to the buffer index
 *
 * Return: the number of characters printed
 */
void print_buffer(char b[], int *buff_ind)
{
	write(1, b, *buff_ind);
	*buff_ind = 0;
}

/**
 * _format_specifier - handle a format specifier
 * @b: the buffer
 * @buffer_pos: a pointer to the buffer position
 * @args: argument list
 * @format: the format specifier character
 *
 * Return: void
 */
void _format_specifier(char b[], int *buffer_pos, va_list args, char format)
{
	int len;
	char *str;

	switch (format)
	{
		case 'c':
			b[*buffer_pos] = va_arg(args, int);
			(*buffer_pos)++;
			break;
		case 's':
			str = va_arg(args, char *);
			len = strlen(str);
			if (*buffer_pos + len > BUFF_SIZE - 1)
				print_buffer(b, buffer_pos);
			memcpy(b + *buffer_pos, str, len);
			*buffer_pos += len;
			break;
		case '%':
			b[*buffer_pos] = '%';
			(*buffer_pos)++;
			break;
		default:
			b[*buffer_pos] = '%';
			(*buffer_pos)++;
			b[*buffer_pos] = format;
			(*buffer_pos)++;
			break;
	}
}

/**
 * _printf - print the output of a formatted string
 * @format: The format string
 *
 * Return: The total number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, count = 0, buffer_pos = 0;
	char b[BUFF_SIZE];

	va_start(args, format);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			_format_specifier(b, &buffer_pos, args, format[i]);
		}
		else
		{
			b[buffer_pos] = format[i];
			buffer_pos++;
			if (buffer_pos == BUFF_SIZE - 1)
				print_buffer(b, &buffer_pos);
		}
	}
	print_buffer(b, &buffer_pos);
	va_end(args);
	return (count);
}
