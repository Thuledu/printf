#include "main.h"
void prints_buffer(char buff[], int *buff_index);
/**
 * _printf - function that produces output according to a format.
 * @format: The format.
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int a;
	int prints = 0, prints_chars = 0, buff_index = 0;
	int flag, precisions, width, sizes;
	va_list list_str;
	char buff[BUFFER_SIZE];

	if (format == NULL)
	{
		return (-1);
	}

	va_start(list_str, format);

	for (a = 0; format && format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			buff[buff_index++] = format[a];
			if (buff_index == BUFFER_SIZE)
				prints_buffer(buff, &buff_index);
			/* write(1, &format[a], 1);*/
			prints_chars++;
		}
		else
		{
			prints_buffer(buff, &buff_index);
			flag = get_flag(format, &a);
			precisions = get_precisions(format, &a, list_str);
			width = get_width(format, &a, list_str);
			sizes = get_sizes(format, &a);
			++a;
			prints = handle_print(format, &a, list_str, buff,
					flag, precisions, width, sizes);
			if (prints == -1)
				return (-1);
			prints_chars += prints;
		}
	}
	prints_buffer(buff, &buff_index);
	va_end(list_str);
	return (prints_chars);
}

/**
 * prints_buffer - The printed contents of the buffer if it exist
 * @buff: The array of chars
 * @buff_index: The index, which add to next char, represents the length.
 * return: 0 (Success)
 */
void prints_buffer(char buff[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buff[0], *buff_index);
	*buff_index = 0;
}
