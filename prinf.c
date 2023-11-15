#include "main.h"
#include <stdarg.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == '\0')
                break;

            if (*format == 'c')
                count += _print_char(va_arg(args, int));
            else if (*format == 's')
                count += _print_str(va_arg(args, char *));
            else if (*format == '%')
                count += _putchar('%');
            else
                _putchar(*format);
        }
        else
            count += _putchar(*format);
        format++;
    }

    va_end(args);

    return count;
}

