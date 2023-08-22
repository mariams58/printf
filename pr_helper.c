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
	if (c >= 0)
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
	char *str1 = "(null)";
	int count = 0, i;

	str = va_arg(pt, char *);

	if (!str)
		str = str1;
	for (i = 0; str[i] != '\0'; i++)
		count += _putchar(str[i]);
	return (count);
}
/**
  * to_bin - converts unsigned int to binary
  * @pt: a variable arg pt
  *
  * Return: num of byte printed
  */
int to_bin(va_list pt)
{
	int count = 0;
	unsigned int x, i, j = 0;
	int bin_ar[1024];

	x = va_arg(pt, int);
	if (x <= 0)
		count += _putchar(0 + '0');
	if (x > UINT_MAX)
		x = UINT_MAX;
	i = 0;
	while (x > 0)
	{
		bin_ar[i] = x % 2;
		x = x / 2;
		i++;
	}
	for (j = i - 1; j > 0; j--)
		count += _putchar(bin_ar[j] + '0');
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
	if (val <= INT_MIN)
		val = INT_MIN;
	if (val >= INT_MAX)
		val = INT_MAX;
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
