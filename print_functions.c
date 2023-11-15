#include "main.h"
#include <stddef.h>

/**
 * _print_str - Prints a string
 * @str: The string to print
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _print_str(char *str)
{
    int count = 0;

    if (str == NULL)
        str = "(null)";

    while (*str)
    {
        count += _putchar(*str);
        str++;
    }

    return count;
}
