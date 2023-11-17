#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%' && *(format + 1) != '\0')
        {
            format++; /* Move past '%' */
            switch (*format)
            {
                case 'c':
                    count += putchar(va_arg(args, int));
                    break;
                case 's':
                    count += puts(va_arg(args, char *));
                    break;
                case '%':
                    count += putchar('%');
                    break;
                default:
                    count += putchar('%');
                    count += putchar(*format);
            }
        }
        else
        {
            count += putchar(*format);
        }

        format++;
    }

    va_end(args);

    return count;
}
