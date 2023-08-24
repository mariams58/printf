#include "main.h"
/**
  * out_x - prints out a num in hexadecimal
  * @num: num given
  *
  * Return: num of byte printed
  */
int out_x(int num)
{
	int count = 0, i = 0;
	int j, y, bin_ar[32];

	while (num > 0)
	{
		bin_ar[i] = num % 16;
		num = num / 16;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		if (bin_ar[j] < 10)
			count += _putchar(bin_ar[j] + '0');
		else
		{
			y = bin_ar[j] - 9;
			count += _putchar(64 + y);
		}
	}
	return (count);
}

/**
  * to_hex - converts unsigned int to binary
  * @pt: a variable arg pt
  *
  * Return: num of byte printed
  */
int to_hex(va_list pt)
{
	int count = 0, i, j = 0;
	unsigned int x;
	unsigned int bin_ar[32], y;

	x = va_arg(pt, int);
	if (x <= 0)
		count += _putchar(0 + '0');
	if (x > UINT_MAX)
		x = UINT_MAX;
	i = 0;
	while (x > 0)
	{
		bin_ar[i] = x % 16;
		x = x / 16;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		if (bin_ar[j] < 10)
			count += _putchar(bin_ar[j] + '0');
		else
		{
			y = bin_ar[j] - 9;
			count += _putchar(96 + y);
		}
	}
	return (count);
}

/**
  * to_heX - converts unsigned int to binary
  * @pt: a variable arg pt
  *
  * Return: num of byte printed
  */
int to_heX(va_list pt)
{
	int count = 0, j, i, y;
	unsigned int x, bin_ar[32];

	x = va_arg(pt, int);
	if (x <= 0)
		count += _putchar(0 + '0');
	if (x > UINT_MAX)
		x = UINT_MAX;
	i = 0;
	while (x > 0)
	{
		bin_ar[i] = x % 16;
		x = x / 16;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		if (bin_ar[j] < 10)
			count += _putchar(bin_ar[j] + '0');
		else
		{
			y = bin_ar[j] - 9;
			count += _putchar(64 + y);
		}
	}

	return (count);
}
