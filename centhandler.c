#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "main.h"

/**
 * centhandler - check the code
 * @ags: the list of variable args
 * @ptr: the specifier
 * Return: the # of bytes written
 */
int centhandler(va_list ags, const char **ptr)
{
	if (*((*ptr) + 1) == '%')
	{
		(*ptr)++;
		return (write(1, "%", 1));
	}
	if (*((*ptr) + 1) == 's')
	{
		(*ptr)++;
		return (stringprint(ags));
	}

	if (*((*ptr) + 1) == 'c')
	{
		(*ptr)++;
		return (charprint(ags));
	}
	write(1, *ptr, 2);
	(*ptr)++;
	return (2);
}
