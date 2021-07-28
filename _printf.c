#include "holberton.h"

/**
 * arg_printer - find a way to print according to the given format
 * @format: possible format specifier
 * @args: pointer to the arguments
 * Return: The number of characters printed
 */
int arg_printer(va_list args, const char *format)
{
	int i, so_len = 0;
	char c;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (!format[i])
				return (-1);
			switch (format[i + 1])
			{
			case 'c':
				c = (char)va_arg(args, int), _putchar(c), i++;
				break;
			case 's':
				so_len += print_str(args), so_len--, i++;
				break;
			case '%':
				_putchar('%'), i++;
				break;
			case '\0':
				so_len = -2; break;
			case 'd':
			case 'i':
				so_len += print_int(args), so_len--;
				break;
			case 'R':
				so_len += print_rot13(args), so_len--, i++;
				break;
			default:
				_putchar('%');
				break;
			}
		}
		else
			_putchar(format[i]);
		so_len++;
	}
	return (so_len);
}

/**
 * _printf - prints anything
 * @format: list of argument types passed to the function
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int so_len;
	va_list arg_ptr;

	va_start(arg_ptr, format);
	if (format == NULL)
		return (-1);
	so_len = arg_printer(arg_ptr, format);
	va_end(arg_ptr);
	return (so_len);
}
