#include "main.h"

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

            switch (*format)
            {
            case 's':
                count += _print_str(va_arg(args, char *));
                break;
            case 'd':
            case 'i':
                count += _print_int(va_arg(args, int));
                break;
            default:
                _putchar('%');
                _putchar(*format);
                count += 2;
                break;
            }
        }
        else
        {
            _putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);

    return count;
}
