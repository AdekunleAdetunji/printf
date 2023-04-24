#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void int_str(va_list arg_list, int *i, int *count);
char *_itoa(int num);
char *_reverse(char *str);
void print_integer(int n);
int _printf(const char *format, ...);
#endif
