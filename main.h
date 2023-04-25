#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void int_str(va_list arg_list, int *i, int *count);
void int_s(va_list arg_list, int *i, int *count);
void print_integer(int n);
int _printf(const char *format, ...);
void convert_to_binary(unsigned int n);
void char_s(const char *format, va_list arg_list, int *i, int *count);

#endif
