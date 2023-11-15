#include "main.h"

int _print_int(int num)
{
    int count = 0;

    if (num == 0)
        return _putchar('0');

    if (num < 0)
    {
        count += _putchar('-');
        num = -num;
    }

    if (num / 10)
        count += _print_int(num / 10);

    count += _putchar((num % 10) + '0');

    return count;
}

