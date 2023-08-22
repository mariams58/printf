#include "main.h"
/**
  * out_char - prints out a char
  * @pt: a variable arg pt
  *
  * Return: num of byte printed to the stdout
  */
int out_char(va_list pt)
{
	char c;
	int count = 0;

	c = (char)va_arg(pt, int);
	count += _putchar(c);	
	return (count);
}

/**
  * out_string - prints out a char
  * @pt: a variable arg pt
  *
  * Return: num of byte printed to the stdout
  */
int out_string(va_list pt)
{
	char *str;
	int count = 0, i;

	str = va_arg(pt, char *);
	for (i = 0; str[i] != '\0'; i++)
		count += _putchar(str[i]);
	return (count);
}

/**
  * out_num - prints out a char
  * @pt: a variable arg pt
  *
  * Return: num of byte printed to the stdout
  */
int out_num(va_list pt)
{
	int count = 0, val;

	val = va_arg(pt, int);
	if (val < 0)
	{
		count += _putchar(45);
		val = -val;
	}
	count += print_num(val);
	return (count);
}

/**
  * print_num - prints out a given num with putchar
  * @num: number given
  *
  * Return: number of bytes printed to stdout
  */
int print_num(int num)
{
	int count = 0;

	if (num / 10)
		count += print_num(num / 10);
	count += _putchar((num % 10) + '0');
	return (count);
}
