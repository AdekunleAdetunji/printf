#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <string.h>

void print_buffer(char b[], int *buff_ind);
int _printf(const char *format, ...);
int _strlen_recursion(char *s);
int _write_char(char c);
void _format_specifier(char b[], int *buffer_pos, va_list args, char format);
#define BUFF_SIZE 1024
#endif
