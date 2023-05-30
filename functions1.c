#include "main.h"
#include <stdio.h>

/** PRINTS THE UNSIGNED NUMBER */
/**
 * print_unsigned - Prints the unsigned number
 * @types: Lists the arguments
 * @buff: Buffer array that handles prints
 * @flag: Calculates flags that are active
 * @precisions: Specification of the precisions
 * @width: retrieves width.
 * @sizes: Specifier for size
 * Return: Number of printed chars
 */
int print_unsigned(va_list types, char buff[],
		int flag, int precisions, int width, int sizes)
{
	unsigned long int number = va_arg(types, unsigned long int);
	int a = BUFF_SIZE - 2;

	number = convert_size_unsgnd(number, sizes);

	if (number == 0)
	{
		buff[a--] = '0';
	}

	buff[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buff[a--] = (number % 10) + '0';
		number /= 10;
	}

	a++;

	return (write_unsgnd(0, a, buff, flag, precisions, width, sizes));
}


/** PRINTS THE UNSIGNED NUMBER IN OCTAL */
/**
 * print_octal - Prints the unsigned number in an octal notation
 * @types: Lists the arguments
 * @buff: Buffer array that handles prints
 * @flag: Calculates flags that are active
 * @precisions: Specification of the precisions
 * @width: retrieves width.
 * @sizes: Specifier for size
 * Return: Number of printed chars
 */
int print_octal(va_list types, char buff[],
		int flag, int precisions, int width, int sizes)
{
	unsigned long int number = va_arg(types, unsigned long int);
	int a = BUFF_SIZE - 2;
	unsigned long int init_number = number;

	UNUSED(width);

	number = convert_size_unsgnd(number, sizes);

	if (number == 0)
		buff[a--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buff[a--] = (number % 8) + '0';
		number /= 8;
	}

	if (flag & F_HASH && init_number != 0)
		buff[a--] = '0';

	a++;

	return (write_unsgnd(0, a, buff, flag, precisions, width, sizes));
}


/** PRINTS THE UNSIGNED NUMBER IN HEXADECIMAL */
/**
 * print_hexadecimal - Prints the unsigned number in an hexadecimal notation
 * @types: Lists the arguments
 * @buff: Buffer array that handles prints
 * @flag: Calculates flags that are active
 * @precisions: Specification of the precisions
 * @width: retrieves width.
 * @sizes: Specifier for size
 * Return: Number of printed chars
 */
int print_hexadecimal(va_list types, char buff[],
		int flag, int precisions, int width, int sizes)
{
	return (print_hexa(types, "0123456789abcdef", buff,
				flag, 'x', precisions, width, sizes));
}


/** PRINTS THE UNSIGNED NUMBER IN UPPER HEXADECIMAL */
/**
 * print_hexa_upper - Prints the unsigned number
 * in an upper hexadecimal notation
 * @types: Lists the arguments
 * @buff: Buffer array that handles prints
 * @flag: Calculates flags that are active
 * @precisions: Specification of the precisions
 * @width: retrieves width.
 * @sizes: Specifier for size
 * Return: Number of printed chars
 */
int print_hexa_upper(va_list types, char buff[],
		int flag, int precisions, int width, int sizes)
{
	return (print_hexa(types, "0123456789ABCDEF", buff,
				flag, 'X', precisions, width, sizes));
}


/** PRINTS THE HEXADECIMAL NUMBER IN LOWER OR UPPER CASE */
/**
 * print_hexa - Hexadecimal number printed in lower or upper
 * @types: Lists the arguments
 * @maps_to: The number is mapped to an array of values
 * @buff: Buffer array that handles prints
 * @flag: Calculates flags that are active
 * @flag_ch: Calculates an active flag
 * @precisions: Specification of the precisions
 * @width: retrieves width.
 * @sizes: Specifier for size
 * Return: Number of printed chars
 */
int print_hexa(va_list types, char maps_to[], char buff[],
		int flag, char flag_ch, int precisions, int width, int sizes)
{
	unsigned long int number = va_arg(types, unsigned long int);
	int a = BUFF_SIZE - 2;
	unsigned long int init_number = number;

	UNUSED(width);

	number = convert_size_unsgnd(number, sizes);

	if (number == 0)
		buff[a--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buff[a--] = maps_to[number % 16];
		number /= 16;
	}

	if (flag & F_HASH && init_number != 0)
	{
		buff[a--] = flag_ch;
		buff[a--] = '0';
	}

	a++;

	return (write_unsgnd(0, a, buff, flag, precisions, width, sizes));
}

