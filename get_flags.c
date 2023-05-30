#include "main.h"

/**
 * get_flags - Calculates the active flags
 * @format: Formatted string to print arguments
 * @a: takes in the parameters.
 * Return: The flag
 */
int get_flags(const char *format, int *a)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARRAY[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
	int flag = 0;
	int m, curr_w;

	for (curr_w = *a + 1; format[curr_w] != '\0'; curr_w++)
	{
		for (m = 0; FLAGS_CH[m] != '\0'; m++)
			if (format[curr_w] == FLAGS_CH[m])
			{
				flag |= FLAGS_ARRAY[m];
				break;
			}

		if (FLAGS_CH[m] == 0)
			break;
	}

	*a = curr_w - 1;

	return (flag);
}
