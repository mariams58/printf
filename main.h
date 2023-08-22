#ifndef _MAIN_H_
#define _MAIN_H_

#include <limits.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

/**
 * struct get_spec  - Struct get_spec
 *
 * @spec: The operator
 * @f: The function associated
 */
typedef struct get_spec
{
	char *spec;
	int (*f)(va_list pt);
} op_spec;

int _putchar(char c);
int _printf(const char *format, ...);
int (*handle_format(const char *str, int idx))(va_list);
int out_num(va_list pt);
int out_char(va_list pt);
int out_toi(va_list pt);
int out_string(va_list pt);
int to_bin(va_list pt);
int print_num(int num);

#endif
