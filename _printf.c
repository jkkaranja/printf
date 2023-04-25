#include "main.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
/**
 * _printf - produces output according to the format
 *
 * @format: character string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, printed_count = 0;

	va_list args;

	va_start(args, format);
	while (format && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			switch (format[i])
			{
				case 'c':
				{
					printed_count = va_arg(args, int);
					printed_count++;
					break;
				}
				case 's':
				{
					char *str = va_arg(args, char *);
					fputs(str, stdout);
					break;
				}
				case '%':
				{
					printed_count++;
					break;
				}
				default:
				break;
			}
			++i;
		}
		else
		{
			printed_count++;
		}
		++i;
	}
	va_end(args);
	return (printed_count);
}
