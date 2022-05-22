#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "main.h"

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

	va_start(argums, format);

	while (i < len)
	{
		if (*(format + i) == '%')
		{
			if (*(format + 1 + i) == 's')
				count += printf("%s", va_arg(argums, char *));
			else if (*(format + 1 + i) == 'c')
				count += printf("%c", va_arg(argums, char *));
			i++;
		}
		else
			printf("%c", *(format + i));
		i++;
	}
	va_end(argums);
	return (count);
}
