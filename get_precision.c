#include "main.h"

/**
 * get_precision - calc the precis of print
 * @format: foramte string
 * @i: list of args
 * @list: list of arrgs
 * Return: returns precision
 **/

int get_precision(const char *format, int *i, va_list list)
{
	int cur_i = *i + 1;
	int precision = -1;

	if (format[cur_i] != '.')
		return (precision);
	precision = 0;
	for (cur_i += 1; format[cur_i] != '\0'; cur_i++)
	{
		if (is_digit(format[cur_i]))
		{
			precision *= 10;
			precision += format[cur_i] - '0';
		}
		else if (format[cur_i] == '*')
		{
			cur_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = cur_i - 1;
	return (precision);
}
