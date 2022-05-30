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
	int written = 0;
	const char *ptr = format;
	int len;

	va_start(ags, format);
	if (ptr == NULL)
		return (0);

	len = strlen(format);
	while (len > 0)
	{
		if (*ptr == '%')
		{
			ptr++;
			len--;
			written += centhandler(ags, ptr);
			ptr++;
			len--;
			continue;
		}
		written += write(1, ptr, 1);
		ptr++;
		len--;
	}
	return (written);
}
