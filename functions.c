#include "main.h"
#include <stdio.h>
/** PRINT CHAR */
/**
 * print_char - Prints char
 * @types: Lists the arguments
 * @buff: Buffer array that handles prints
 * @flag:  Calculates flags that are active
 * @precisions: Specification of the precisions
 * @width: retrieves the Width
 * @sizes: Specifier for size
 * Return: Number of printed chars
 */
int print_char(va_list types, char buff[],
	int flag, int precisions, int width, int sizes)
{
	char g = va_arg(types, int);

	return (handle_write_char(g, buff, flag, precisions, width, sizes));
}

/** PRINTS A STRING */
/**
 * prints_string - Prints string
 * @types: Lists the arguments
 * @buff: Buffer array that handles prints
 * @flag:  Calculates flags that are active
 * @precisions: Specification of the precisions
 * @width: retrieves width.
 * @sizes: Specifier for size
 * Return: Number of printed chars
 */
int print_string(va_list types, char buff[],
		int flag, int precisions, int width, int sizes)
{
	int a;
	int len = 0;
	char *string = va_arg(types, char *);

	UNUSED(buff);
	UNUSED(flag);
	UNUSED(precisions);
	UNUSED(width);
	UNUSED(sizes);
	if (string == NULL)
	{
		string = "(null)";
		if (precisions >= 6)
		{
			string = "  ";
		}
	}

	while (string[len] != '\0')
		len++;

	if (precisions >= 0 && precisions < len)
		len = precisions;

	if (width > len)
	{
		if (flag & F_MINUS)
			write(1, &string[0], len);
			for (a = width - len; a > 0; a--)
				write(1, " ", 1);
			return (width);
		else if
			for (a = width - len; a > 0; a--)
				write(1, " ", 1);
			write(1, &string[0], len);
			return (width);
	}
	return (write(1, string, len));
}


/** PRINTS THE PERCENT SIGN */
/**
 * print_percent - Prints the percent sign
 * @types: Lists the arguments
 * @buff: Buffer array that handles prints
 * @flag:  Calculates flags that are active
 * @precisions: Specification of the precisions
 * @width: retrieves width.
 * @sizes: Specifier for size
 * Return: Number of printed chars
 */
int print_percent(va_list types, char buff[],
	int flag, int precisions, int width, int sizes)
{
	UNUSED(types);
	UNUSED(buff);
	UNUSED(flag);
	UNUSED(precisions);
	UNUSED(width);
	UNUSED(sizes);

	return (write(1, "%%", 1));
}

/** PRINTS INT */
/**
 * print_int - Prints int
 * @types: Lists the arguments
 * @buff: Buffer array that handles prints
 * @flag:  Calculates flags that are active
 * @precisions: Specification of the precisions
 * @width: retrieves width.
 * @sizes: Specifier for size
 * Return: Number of printed chars
 */
int print_int(va_list types, char buff[],
		int flag, int precisions, int width, int sizes)
{
	int negative = 0;
	int a = BUFF_SIZE - 2;
	long int d = va_arg(types, long int);
	unsigned long int number;

	d = convert_size_number(d, sizes);

	if (d == 0)
		buff[a--] = '0';

	buff[BUFF_SIZE - 1] = '\0';
	number = (unsigned long int)d;

	if (d < 0)
	{
		number = (unsigned long int)((-1) * d);
		negative = 1;
	}

	while (number > 0)
	{
		buff[a--] = (number % 10) + '0';
		number /= 10;
	}

	a++;

	return (write_number(negative, a, buff, flag, precisions, width, sizes));
}


/** PRINTS BINARY */
/**
 * print_binary - Prints the unsigned number
 * @types: Lists the arguments
 * @buff: Buffer array that handles prints
 * @flag: Calculates flags that are active
 * @precisions: Specification of the precisions
 * @width: retrieves width.
 * @sizes: Specifier for size
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buff[],
	int flag, int precisions, int width, int sizes)
{
	unsigned int d, e, a, sum;
	unsigned int b[32];
	int c;

	UNUSED(buff);
	UNUSED(flag);
	UNUSED(precisions);
	UNUSED(width);
	UNUSED(sizes);

	d = va_arg(types, unsigned int);

	e = 2147483648; /* (2 ^ 31) */
	b[0] = d / e;
	for (a = 1; a < 32; a++)
	{
		e /= 2;
		b[a] = (d / e) % 2;
	}
	for (a = 0, sum = 0, c = 0; a < 32; a++)
	{
		sum += b[a];
		if (sum || a == 31)
		{
			char k = '0' + b[a];

			write(1, &k, 1);
			c++;
		}
	}
	return (c);
}
