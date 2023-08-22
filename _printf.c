#include "main.h"
/**
  * handle_format - handles prinf format specifiers
  * @str: pointer to format sting
  * @idx: index of the specifier in the forat string
  *
  * Return: a function pointer
  */
int (*handle_format(const char *str, int idx))(va_list)
{
	op_spec fmt[] = {
		{"c", out_char},
		{"s", out_string},
		{"d", out_num},
		{"i", out_num},
		{"u", out_num},
		{NULL, NULL},
	};
	int j = 0;

	while (j < 5)
	{
		if (str[idx + 1] == fmt[j].spec[0])
			return (fmt[j].f);
		j++;
	}
	return (NULL);
}

/**
  * _printf - prints out a formatted string
  * @format: pointer to string that includes format specifier
  *
  * Return: the number of bytes printed to the stdout
  */
int _printf(const char *format, ...)
{
	int count = 0, idx = 0;
	va_list ap;
	int (*func)(va_list);

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (format[idx] != '\0')
	{
		if (format[idx] == '%')
		{
			if (!format[idx + 1])
				return (-1);
			if (format[idx] == format[idx + 1])
			{
				count += _putchar(format[idx + 1]);
				idx += 2;
			}
			func = (*handle_format)(format, idx);
			if (func == NULL)
			{
				count += _putchar(format[idx]);
				idx += 1;
			}
			else
			{
				count += func(ap);
				idx = idx + 2;
			}
		}
		else
		{
			_putchar(format[idx]);
			count += 1;
			idx++;
		}
	}
	va_end(ap);
	return (count);
}
