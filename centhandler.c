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
int centhandler(va_list ags, const char *ptr)
{
	if (*ptr == 's')
		return (stringprint(ags));

	if (*ptr == 'c')
		return (charprint(ags));
	return (0);
}
