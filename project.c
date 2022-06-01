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
 * Return: Always 0 when success
 */
int _printf(const char *format, ...)
{
	va_list ags;
	int count = 0;
	int written = 0;
	const char *ptr_cur = format;

	va_start(ags, format);
	if (ptr_cur == NULL)
		return (0);
	count = strlen(ptr_cur);
	while (count > 0)
	{
		if (*ptr_cur == '%')
		{
			if (count == 1)
			{
				count--;
				continue;
			}
			count--;
			written += centhandler(ags, &ptr_cur);
			ptr_cur++;
			count--;
			continue;
		}
		written += write(1, ptr_cur, 1);
		ptr_cur++;
		count--;
	}
	return (written);
}
