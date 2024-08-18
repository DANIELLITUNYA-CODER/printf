#include "main.h"
#include <limits.h>
#include <stdio.h>

/**
 * _printf - produces output according to a format
 * @format: format string containing the characters and the specifiers
 * Description: this function will call the get_print() function that
 * will
 * determine which printing function to call depending on the conversion
 * specifiers contained into fmt
 * Return: length of the formatted output string
 */
//the below function indicates _printf returns an integer and accepts a  format strings followed by variable number of arguemnets 
int _printf(const char *format, ...)
{
//this declare a function pointer "pfunc" that points to a function taking a va_list and a flag_t structure which conatins a formating output
	int (*pfunc)(va_list, flags_t *);
	//this pointer will be used to iterate through format string
	const char *p;
	//the va_list is used to handle the variable argument passed to the function, 
	va_list arguments;
	flags_t flags = {0, 0, 0};
	register int count = 0;
//the va_start macro initializes arguments to retrirve the additiomal argumnets
	va_start(arguments, format);
/*this is input validation checks ensure taht if  the format string is valid 
*r if it starts with a % character followed by nothing (meaning there’s no valid format specifier). 
*In either case, it returns -1, indicating an error.
*/
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
//
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (get_flag(*p, &flags))
				p++;
			pfunc = get_print(*p);
			count += (pfunc)
				? pfunc(arguments, &flags)
				: _printf("%%%c", *p);
		} else
			count += _putchar(*p);
	}
	_putchar(-1);
	va_end(arguments);
  	return (count);

}
