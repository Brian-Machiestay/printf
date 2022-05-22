#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "main.h"

/**
 * _printf - prints like printf
 * @format: the specification
 * Return: 0 when right
 */
int _printf(const char *format, ...)
{
	va_list argums;
	int count = 0;
	int i = 0;
	int len = strlen(format);
	char *str;
	int lenstr;
	char new;

	va_start(argums, format);

	while (len > 0)
	{
		if (*(format) == '%')
		{
			format++;
			if (*format == 's')
			{
				str = va_arg(argums, char *);
				lenstr = strlen(str);
				count += write(1, str, lenstr);
				format++;
			}
			else if (*format == 'c')
			{
				i = va_arg(argums, int);
				new = (char)i;
				count += write(1, &new, 1);
				format++;
			}
		}
		else
		{
			count += write(1, format, 1);
			i++;
			format++;
		}
		len = strlen(format);
	}
	va_end(argums);
	return (count);
}
