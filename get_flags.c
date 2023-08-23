#include "main.h"

/**
 * get_flags - Calculates active flags.
 * @format: formatted string in which to print the arguments.
 * @i: take a parameter.
 * Return: flags
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8 16 */
	int h, curr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (h = 0; FLAGS_CH[h] != '\0'; h++)
			if (format[curr_i] == FLAGS_CH[h])
			{
				flags |= FLAGS_ARR[h];
				break;
			}
		if (FLAGS_CH[h] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flags);
