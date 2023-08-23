#include "main.h"
/**
 * print_unsigned - Prints a unsigned number
 * @types: the list of args
 * @buffer: buffer aary to hnadle
 * @flags: calculate active flags
 * @width: gets width
 * @precision: presicion of specifque
 * @size: size specifier
 * Return: returns number of chars printed
 */

int print_unsigned(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int nmbs = va_arg(types, unsigned long int);

	nmbs = convert_size_unsgnd(nmbs, size);
	if (nmbs == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (nmbs > 0)
	{
		buffer[i--] = (nmbs % 10) + '0';
		nmbs /= 10;
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/**
 * print_octal - Prints a unsigned in octal
 * @types: the list of args
 * @buffer: buffer aary to hnadle
 * @flags: calculate active flags
 * @width: gets width
 * @precision: presicion of specifque
 * @size: size specifier
 * Return: returns number of chars printed
 */
int print_octal(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int nmbs = va_arg(types, unsigned long int);
	unsigned long int int_nm = nmbs;

	UNUSED(width);

	nmbs = convert_size_unsgnd(nmbs, size);
	if (nmbs == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (nmbs > 0)
	{
		buffer[i--] = (nmbs % 8) + '0';
		nmbs /= 8;
	}
	if (flags & F_HASH && int_nm != 0)
		buffer[i--] = '0';
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/**
 * print_hexadecimal - Prints an unsigned number in hexa
 * @types: the list of args
 * @buffer: buffer aary to hnadle
 * @flags: calculate active flags
 * @width: gets width
 * @precision: presicion of specifque
 * @size: size specifier
 * Return: returns number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer, flags, 'x',
				width, precision, size));
}

int print_hexa_upper(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer, flags, 'X',
				width, precision, size));
}
/**
 * print_hexa - Prints a hexadecimal number in low or up
 * @types: list of argss
 * @map_to: array to map in number
 * @buffer: Buffer to handle
 * @flags: calculates flags
 * @flag_ch: calculate actv flags
 * @width: gets the width
 * @precision: get the precis
 * @size: size of it
 * Return: returns  the number of chars
 */
int print_hexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int nmbs = va_arg(types, unsigned long int);
	unsigned long int int_nm = nmbs;

	UNUSED(width);

	nmbs = convert_size_unsgnd(nmbs, size);
	if (nmbs == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (nmbs > 0)
	{
		buffer[i--] = map_to[nmbs % 16];
		nmbs /= 16;
	}
	if (flags & F_HASH && int_nm != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
