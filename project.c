#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "main.h"

/**
 * convertstr - check the code
 * @s: the str to convert
 * @format: the specifier
 * Return: an int
 */
int convertstr(char *s, const char *format)
{
	int lenstr = 0;
	int count = 0;

	lenstr = strlen(s);
	count += write(1, s, lenstr);
	format++;
	return (count);
}

/**
 * _printf - prints like printf
 * @format: the specification
 * Return: Always 0
 */
int _printf(const char *format, ...)
{
	va_list argums;
	int count = 0;
	int i = 0;
	int len = strlen(format);
	char *str;
	/* int lenstr;*/
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
				if (str != NULL)
				{
					count += convertstr(str, format);
					format++;
				}
			}
			else if (*format == 'c')
			{
				i = va_arg(argums, int);
				if (i)
				{
					new = (char)i;
					count += write(1, &new, 1);
					format++;
				}
			}
		}
		else
		{
			count += write(1, format, 1);
			format++;
		}
		len = strlen(format);
	}
	va_end(argums);
	return (count);
}
