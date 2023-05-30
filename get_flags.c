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
	const char FLAG_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAG_ARRAY[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
	int flag = 0;
	int m, curr_w;

	for (curr_w = *a + 1; format[curr_w] != '\0'; curr_w++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr_w] == FLAG_CH[m])
			{
				flag |= FLAG_ARRAY[m];
				break;
			}

		if (FLAG_CH[m] == 0)
			break;
	}

	*w = curr_w - 1;

	return (flag);
}
