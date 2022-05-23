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
 * Return: an int
 */
int convertstr(char *s)
{
	int lenstr = 0;
	int count = 0;

	if (s != NULL)
	{
		lenstr = strlen(s);
		count += write(1, s, lenstr);
	}
	return (count);
}
/**
 * converti - check the code
 * @i: the char int  to convert
 * Return: an int
 */
int converti(int i)
{
	int count = 0;
	int new;

	if (i)
	{
		new = (char)i;
		count += write(1, &new, 1);
	}
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

	va_start(argums, format);

	while (len > 0)
	{
		if (*(format) == '%')
		{
			format++;
			if (*format == 's')
			{
				str = va_arg(argums, char *);
				count += convertstr(str);
				format++;
			}
			else if (*format == 'c')
			{
				i = va_arg(argums, int);
				count += converti(i);
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
	return (count - 3);
}
