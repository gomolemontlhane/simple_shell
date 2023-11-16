#include "shell.h"
#include <stdio.h>
#include <stdarg.h>

/**
 *my_printf - Custom printf function supporting %s and %d specifiers
 *@format: The format string
 *@...: Additional arguments corresponding to the specifiers
 */
void my_printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && *(format + 1) == 's')
		{
			char *str = va_arg(args, char *);

			my_printf("%s", str);
			format += 2;	/* Move to the next format specifier */
		}
		else if (*format == '%' && *(format + 1) == 'd')
		{
			int num = va_arg(args, int);

			my_printf("%d", num);
			format += 2;	/* Move to the next format specifier */
		}
		else
		{
			putchar(*format);
			format++;
		}
	}

	va_end(args);
}
