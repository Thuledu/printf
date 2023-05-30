#include "main.h"
#include <stdio.h>

/** PRINTS THE POINTER */

/**
 * print_pointer - Displays a pointer variable's value
 * @types: Lists the arguments
 * @buff: Buffer array that handles prints
 * @flag: Calculates flags that are active
 * @precisions: Specification of the precisions
 * @width: retrieves width.
 * @sizes: Specifier for size
 * Return: Number of printed chars
 */
int print_pointer(va_list types, char buff[],
		int flag, int precisions, int width, int sizes)
{
	unsigned long num_address;
	char maps_to[] = "0123456789abcdef";
	void *address = va_arg(types, void *);
	char extra_s = 0, padd = ' ';
	int index = BUFFER_SIZE - 2, len = 2, padd_starts = 1;

	UNUSED(sizes);
	UNUSED(width);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	buff[BUFFER_SIZE - 1] = '\0';
	UNUSED(precisions);

	num_address = (unsigned long)address;

	while (num_address > 0)
	{
		buff[index--] = maps_to[num_address % 16];
		num_address /= 16;
		len++;
	}

	if ((flag & F_ZERO) && !(flag & F_MINUS))
		padd = '0';
	if (flag & F_PLUS)
	{
		extra_s = '+', len++;
	}
	else if (flag & F_SPACE)
	{
		extra_s = ' ', len++;
	}
	index++;

	/*return (write(1, &buff[a], BUFFER_SIZE - a - 1));*/
	return (write_pointer(buff, index, len,
				width, flag, padd, extra_s, padd_starts));
}


/** PRINTS THE NON PRINTABLE **/

/**
 * print_non_printable - Prints hexadecimal
 * ascii codes for characters that are not printable.
 * @types: Lists the arguments
 * @buff: Buffer array that handles prints
 * @flag: Calculates flags that are active
 * @precisions: Specification of the precisions
 * @width: retrieves width.
 * @sizes: Specifier for size
 * Return: Number of printed chars
 */
int print_non_printable(va_list types, char buff[],
		int flag, int precision, int width, int sizes)
{
	char *string = va_arg(types, char *);
	int a = 0, offst = 0;

	UNUSED(flag);
	UNUSED(precisions);
	UNUSED(width);
	UNUSED(sizes);

	if (string == NULL)
		return (write(1, "(null)", 6));

	while (string[a] != '\0')
	{
		if (is_printable(string[a]))
		{
			buff[a + offst] = string[a];
		}
		else
		{
			offst += append_hexa_code(string[a], buff, a + offst);
		}
		a++;
	}
	buff[a + offst] = '\0';

	return (write(1, buff, a + offst));
}


/** PRINTS THE REVERSE */

/**
 * print_reverse - Reverse string is printed.
 * @types: Lists the arguments
 * @buff: Buffer array that handles prints
 * @flag: Calculates flags that are active
 * @precisions: Specification of the precisions
 * @width: retrieves width.
 * @sizes: Specifier for size
 * Return: Number of printed chars
 */

int print_reverse(va_list types, char buff[],
	int flag, int precisions, int width, int sizes)
{
	char *string;
	int a, c = 0;

	UNUSED(buff);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(sizes);

	string = va_arg(types, char *);

	if (string == NULL)
	{
		UNUSED(precisions);

		string = ")Null(";
	}
	for (a = 0; string[a]; a++)
		;

	for (a = a - 1; a >= 0; a--)
	{
		char f = string[a];

		write(1, &f, 1);
		c++;
	}
	return (c);
}


/** PRINTS THE STRING IN ROT13 */

/**
 * print_rot13string - string printed in rot13.
 * @types: Lists the arguments
 * @buff: Buffer array that handles prints
 * @flag: Calculates flags that are active
 * @precisions: Specification of the precisions
 * @width: retrieves width.
 * @sizes: Specifier for size
 * Return: Number of printed chars
 */
int print_rot13string(va_list types, char buff[],
		int flag, int precisions, int width, int sizes)
{
	int c = 0;
	unsigned int a, h;
	char t;
	char *string;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	string = va_arg(types, char *);
	UNUSED(buff);
	UNUSED(flag);
	UNUSED(precisions);
	UNUSED(width);
	UNUSED(sizes);

	if (string == NULL)
		string = "(AHYY)";
	for (a = 0; string[a]; a++)
	{
		for (h = 0; input[h]; h++)
		{
			if (input[h] == string[a])
			{
				t = output[h];
				write(1, &t, 1);
				c++;
				break;
			}
		}
		if (!input[h])
		{
			t = string[a];
			write(1, &t, 1);
			c++;
		}
	}
	return (c);
}
