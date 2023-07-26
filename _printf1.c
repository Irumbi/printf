#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - Writes a character to stdout
 * @c: The character to print
 * Return: On success, 1. On error, -1 is returned.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - Custom printf function
 * @format: Format string containing the directives
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			count++;
		}
		else
		{
			format++;
			switch (*format)
			{
			case 'c':
				_putchar(va_arg(args, int));
				count++;
				break;
			case 's':
				count += _print_str(va_arg(args, char *));
				break;
			case '%':
				_putchar('%');
				count++;
				break;
			case 'd':
			case 'i':
				count += _print_int(va_arg(args, int));
				break;
			default:
				_putchar('%');
				_putchar(*format);
				count += 2;
				break;
			}
		}
		format++;
	}

	va_end(args);

	return (count);
}

/**
 * _print_str - Prints a string to stdout
 * @str: The string to print
 * Return: The number of characters printed
 */
int _print_str(char *str)
{
	int count = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		_putchar(*str);
		count++;
		str++;
	}

	return (count);
}

/**
 * _print_int - Prints an integer to stdout
 * @n: The integer to print
 * Return: The number of characters printed
 */
int _print_int(int n)
{
	unsigned int num;
	int count = 0;

	if (n < 0)
	{
		_putchar('-');
		count++;
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10)
		count += _print_int(num / 10);

	_putchar('0' + (num % 10));
	count++;

	return (count);
}
