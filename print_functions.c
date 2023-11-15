#include <unistd.h>

/**
 * _putchar - Writes a character to stdout
 * @c: Character to write
 *
 * Return: Number of bytes written, or -1 on error
 */
static int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * _print_str - Prints a string to stdout
 * @str: String to print
 *
 * Return: Number of bytes printed
 */
int _print_str(char *str)
{
    int count = 0;

    while (*str)
    {
        count += _putchar(*str);
        str++;
    }

    return count;
}

