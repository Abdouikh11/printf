#include "main.h"
void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - The function printf
 * @format: format of the printf
 * Return: That chars that printed
 */

int _printf(const char *format, ...)
{
	int i, prntd = 0, prtchars = 0;
	int flags, width, precision, size, buff_ind = 0;

	va_list pars;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(pars, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			prtchars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, pars);
			precision = get_precision(format, &i, pars);
			size = get_size(format, &i);
			i++;
			prntd = handle_print(format, &i, pars, buffer, flags,
					width, precision, size);
			if (prntd == -1)
				return (-1);
			prtchars += prntd;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(pars);
	return (prtchars);
}
/**
 * print_buffer - Prints the inside of the buffer
 * @buffer: the array of charahctrs
 * @buff_ind: Index at which to add next charch is the lenghth
 *
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
