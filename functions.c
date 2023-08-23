#include "main.h"
/**
 * print_string - function that prints string
 * @types: the list of args
 * @buffer: buffer aary to hnadle
 * @flags: calculate active flags
 * @width: getss width
 * @precision: presicion of specifque
 * @size: size specifiers
 * Return: returns number of chars printed
 **/

int print_sting(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	int flags, width, precision, size;
	int lens = 0, i;
	char *st = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (st == NULL)
	{
		st = "(null)";
		if (precision >= 6)
			st = "      ";
	}
	while (st[lens] != '\0')
		lens++;
	if (precision >= 0 && precision < lens)
		lens = precision;
	if (width > lens)
	{
		if (flags & F_MINUS)
		{
			write(1, &st[0], lens);
			for (i = width - lens; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - lens; i > 0; i--)
				write(1, " ", 1);
			write(1, &st[0], lens);
			return (width);
		}
	}
	return (write(1, st, lens));
}
/**
 * print_char - Prints a char
 * @types: the list of args
 * @buffer: buffer aary to hnadle
 * @flags: calculate active flags
 * @width: gets width
 * @precision: presicion of specifque
 * @size: size specifier
 * Return: returns number of chars printed
 */
int print_char(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	char charss = va_arg(types, int);

	return (handle_write_char(charss, buffer, flags, width,
				precision, size));
}
/**
 * print_percent - Prints precent
 * @types: the list of args
 * @buffer: buffer aary to hnadle
 * @flags: calculate active flags
 * @width: gets width
 * @precision: presicion of specifque
 * @size: size specifier
 * Return: returns number of chars printed
 */
int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precesion);
	UNUSED(size);
	return (write(1, "%%", 1));
}
/**
 * print_int - Prints integers
 * @types: the list of args
 * @buffer: buffer aary to hnadle
 * @flags: calculate active flags
 * @width: gets width
 * @precision: presicion of specifque
 * @size: size specifier
 * Return: returns number of chars printed
 */
int print_int(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int nega = 0;
	long int nm = va_arg(types, long int);
	unsigned long int nums;

	nm = convert_size_number(nm, size);
	if (nm == 0)
		buffer[i--] == '0';
	buffer[BUFF_SIZE - 1] = '\0';
	nums = (unsigned long int)nm;
	if (nm < 0)
	{
		nums = (unsigned long int)((-1) * nm);
		nega = 1;
	}
	while (nums > 0)
	{
		buffer[i--] = (nums % 10) + '0';
		nums /= 10;
	}
	i++;
	return (write_number(nega, i, buffer, flags, width, precision, size));
}
/**
 * print_binary - Prints a unsighned number
 * @types: the list of args
 * @buffer: buffer aary to hnadle
 * @flags: calculate active flags
 * @width: gets width
 * @precision: presicion of specifque
 * @size: size specifier
 * Return: returns number of chars printed
 */
int print_binary(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	unsigned int nm, k, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	nm = va_arg(types, unsigned int);
	k = 2147483648;
	a[0] = nm / k;
	for (i = 1; i < 32; i++)
	{
		k /= 2;
		a[i] = (nm / k) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
