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
 * Return: Always 0
 */
int _printf(const char *format, ...)
{
	va_list ags;
	int count = 0;
	int written = 0;
	const char *ptr = format;

	va_start(ags, format);
	if (ptr == NULL)
		return (-1);
	count = strlen(ptr);
	while (count > 0)
	{
		if (*ptr == '%')
		{
			if (count == 1)
			{
				written = -1;
				count--;
				continue;
			}
			count--;
			written += centhandler(ags, &ptr);
			ptr++;
			count--;
			continue;
		}
		written += write(1, ptr, 1);
		ptr++;
		count--;
	}
	return (written);
}
