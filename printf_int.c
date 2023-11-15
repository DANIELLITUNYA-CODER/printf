#include "main.h"
#include <stdarg.h>

/**
 * _printf - Produces output according to a format
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
        {
            count += _print_int(va_arg(args, int));
            format += 2;
            continue;
        }

        _putchar(*format);
        count++;
        format++;
    }

    va_end(args);

    return count;
}

/**
 * _print_int - Prints an integer
 * @n: The integer to be printed
 *
 * Return: The number of characters printed
 */
int _print_int(int n)
{
    int count = 0;

    if (n < 0)
    {
        _putchar('-');
        count++;
        n = -n;
    }

    if (n / 10)
        count += _print_int(n / 10);

    _putchar(n % 10 + '0');
    count++;

    return count;
}

