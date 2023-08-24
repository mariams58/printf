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
		{"i", out_toi},
		{"u", out_tou},
		{"b", to_bin},
		{"S", to_string},
		{"x", to_hex},
		{"X", to_heX},
		{NULL, NULL},
	};
	int j = 0;

	while (j < 10)
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
		while (format[idx] == '%')
		{
			if (!format[idx + 1] || format[idx + 1] == 32)
				return (-1);
			if (format[idx] == format[idx + 1])
			{
				count += _putchar(format[idx + 1]);
				idx += 2;
			}
			else
			{
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
		}
		count += _putchar(format[idx]);
		idx++;
	}
	va_end(ap);
	return (count);
}

/**
  * to_string - prints out a char
  * @pt: a variable arg pt
  *
  * Return: num of byte printed to the stdout
  */
int to_string(va_list pt)
{
	char *str;
	char *str1 = "(null)";
	int count = 0, i;

	str = va_arg(pt, char *);

	if (!str)
		str = str1;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (!(str[i] > 0 && str[i] < 32) || str[i] >= 127)
			count += _putchar(str[i]);
		else
		{
			count += _putchar(92);
			count += _putchar(120);
			count += out_x(str[i]);
		}
	}
	return (count);
}

/**
  * out_tou - prints out unsigned int
  * @pt: a variable arg
  *
  * Return: num of byte
  */
int out_tou(va_list pt)
{
	int count = 0;
	int val;
	unsigned int bval;

	val = va_arg(pt, int);
	if (val < 1)
		val = 0;
	if (val > INT_MAX)
	{
		bval = val;
		return ((count += print_num(bval)));
	}
	count += print_num(val);
	return (count);
}

/**
  * out_toi - prints out a number
  * @pt: a variable arg pt
  *
  * Return: num of byte printed to the stdout
  */
int out_toi(va_list pt)
{
	int count = 0;
	long int val;

	val = (long int)va_arg(pt, int);
	if (val <= LONG_MIN)
		val = LONG_MIN;
	if (val >= LONG_MAX)
		val = LONG_MAX;
	if (val < 0)
	{
		count += _putchar(45);
		val = -val;
	}
	count += print_num(val);
	return (count);
}
