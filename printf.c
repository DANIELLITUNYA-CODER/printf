#include "main.h"
#include <stdarg.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;

    va_start(args, format);

    while (format && *format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 's')
                count += _print_str(va_arg(args, char *));
            else if (*format == 'd' || *format == 'i')
            {
                int num = va_arg(args, int);
                if (num < 0)
                {
                    count += _putchar('-');
                    num = -num;
                }
                count += _print_int(num);
            }
            else
            {
                count += _putchar('%');
                if (*format)
                    count += _putchar(*format);
            }
        }
        else
        {
            count += _putchar(*format);
        }

        format++;
    }

    va_end(args);

    return count;
}

