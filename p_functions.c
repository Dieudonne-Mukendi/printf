#include "holberton.h"
/**
 * print_str - Print a string
 *@arg_ptr: pointer to the argument
 *Return: number of characters printed
 */
int print_str(va_list arg_ptr)
{
	char *str;
	int i;

	str = va_arg(arg_ptr, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	return (i);
}

/**
 * print_num - Print a number
 *@n: number to print
 *@c: length of the number
 *Return: number of printed characters
 */
int print_num(unsigned int n, int c)
{
	if (n / 10)
		c = print_num(n / 10, c);
	_putchar(n % 10 + '0');
	return (c + 1);
}

/**
 * print_int - Print an integer
 *@arg_ptr: list that contains the format inserted
 *Return: number of the integers printed
 */
int print_int(va_list arg_ptr)
{
	int number, count = 0;
	unsigned int uns_number;

	number = va_arg(arg_ptr, int);
	if (number < 0)
	{
		uns_number = number * -1;
		_putchar('-');
		count = print_num(uns_number, count);
		count += 1;
	}
	else
	{
		uns_number = number;
		count = print_num(uns_number, count);
	}
	return (count);
}

/**
 * print_rot13 - Converts a string into a rot 13 format
 *@arg_ptr: list that contains the format inserted
 *Return: number of the characters
 */
int print_rot13(va_list arg_ptr)
{
	int i, j;
	char a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char r[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *c, *str;

	c = va_arg(arg_ptr, char *);
	if (c == NULL)
		return (0);
	str = malloc(1024);
	if (str == NULL)
		return (-1);
	for (i = 0; c[i] != '\0'; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (c[i] == a[j])
			{
				str[i] = r[j];
				break;
			}
			else
			{
				str[i] = c[i];
			}
		}
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	free(str);
	return (i);
}

/**
 * print_r - prints astring in reverse
 * @r: string to print
 *
 * Return: number of chars printed
 */
int print_r(va_list arg_ptr)
{
	char *str;
	int i, count = 0;

	str = va_arg(arg_ptr, char *);
	if (str == NULL)
		str = ")llun(";
	for (i = 0; str[i]; i++)
		;
	for (i -= 1; i >= 0; i--)
	{
		_putchar(str[i]);
		count++;
	}
	return (count);
}
