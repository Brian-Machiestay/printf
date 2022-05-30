#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "main.h"

/**
 * stringprint - check the code
 * @ags: the str to convert
 * Return: the # of bytes written
 */
int stringprint(va_list ags)
{
	char *str;
	int lenstr = 0;

	str = va_arg(ags, char *);
	lenstr = strlen(str);
	return (write(1, str, lenstr));
}
