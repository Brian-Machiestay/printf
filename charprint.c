#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "main.h"
/**
 * charprint - check the code
 * @ags: the argument list
 * Return: an int
 */
int charprint(va_list ags)
{
	char i;

	i = (char)(va_arg(ags, int));
	return (write(1, &i, 1));
}
