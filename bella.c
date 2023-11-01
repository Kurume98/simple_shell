#include "main.h"

int _printf(const char *format, ...)
{

	va_list list;
	int len;
	int printed_chars = 0;

	va_start(list, format);

	if (format == NULL)
		return (-1);

	while (*format)
	{
	if (*format == '%' && *(format + 1) != '\0')
	{
		format++;
		switch (*format)
		{
			case 'c':
			{
				char c = va_arg(list, int);

				write(1, &c, 1);
				printed_chars++;
				break;
			}
			case 's':
			{
				char *str = va_arg(list, char *);

				if (str == NULL)
					str = "(null)";
				len = 0; /* Initialize len here */
				while (str[len])
					len++;
				write(1, str, len);
				printed_chars += len;
				break;
			}
			case '%':
				write(1, "%", 1);
		printed_chars += 1;
		break;
		}
	}
	else
	{
	write(1, format, 1);
	printed_chars++;
	}
	format++;
	}
	va_end(list);
	return (printed_chars);
}
