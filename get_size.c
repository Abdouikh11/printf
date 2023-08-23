#include "main.h"

/**
 * get_size - calc teh size of args
 * @format: formate string to be prnted
 * @i: list of args
 * Return: return presicse
 **/

int get_size(const char *format, int *i)
{
	int cur_i = *i + 1;
	int sz = 0;

	if (format[cur_i] == 'l')
		sz = S_LONG;
	else if (format[cur_i] == 'h')
		sz = S_SHORT;
	if (sz == 0)
		*i = cur_i - 1;
	else
		*i = cur_i;
	return (sz);
}
