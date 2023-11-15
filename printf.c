#include "main.h"

/**
 * _printf - Produces output according to a format.
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
            if (*format == 's')
                count += _print_str(va_arg(args, char *));
            else if (*format == 'c')
                count += _putchar(va_arg(args, int));
            else if (*format == '%')
                count += _putchar('%');
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

