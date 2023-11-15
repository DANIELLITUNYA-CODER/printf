#include "main.h"
#include <unistd.h>  
#include <stddef.h> 

/**
 * _putchar - Writes a character to the standard output (stdout)
 * @c: The character to be written
 *
 * Return: On success, the number of characters written. On error, -1 is
 * returned and errno is set appropriately.
 */
int _putchar(char c) {
    return write(1, &c, 1);
}

/**
 * _print_char - Prints a character
 * @c: The character to be printed
 *
 * Return: The number of characters printed
 */
int _print_char(int c) {
    _putchar(c);
    return 1;
}

/**
 * _print_str - Prints a string
 * @str: The string to be printed
 *
 * Return: The number of characters printed
 */
int _print_str(char *str) {
    int count = 0;

    if (str == NULL)
        str = "(null)";

    while (*str) {
        _putchar(*str);
        str++;
        count++;
    }

    return count;
}

