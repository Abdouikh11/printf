#include "main.h"

/**
 * print_pointer - Prints value of ptr
 * @types: the list of args
 * @buffer: buffer aary to hnadle
 * @flags: calculate active flags
 * @width: gets width
 * @precision: presicion of specifque
 * @size: size specifier
 * Return: returns number of chars printed
 */
int print_pointer(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	char ex_c = 0, spadd = ' ';
	int indx = BUFF_SIZE - 2, len = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[indx--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		len++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		spadd = '0';
	if (flags & F_PLUS)
		ex_c = '+', len++;
	else if (flags & F_SPACE)
		ex_c = ' ', len++;
	indx++;
	return (write_pointer(buffer, indx, len, width, flags, spadd, ex_c,
				padd_start));
}
/**
 * print_non_printable - Prints ascii codes in hexa
 * @types: the list of args
 * @buffer: buffer aary to hnadle
 * @flags: calculate active flags
 * @width: gets width
 * @precision: presicion of specifque
 * @size: size specifier
 * Return: returns number of chars printed
 */
int print_non_printable(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	int i = 0, offset = 0;
	char *st = va_arg(types, char *);

	UNUSED(flags)
		UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (st == NULL)
		return (write(1, "(null)", 6));
	while (st[i] != '\0')
	{
		if (is_printable(st[i]))
			buffer[i + offset] = st[i];
		else
			offset += append_hex_code(st[i], buffer, i + offset);
		i++;
	}
	buffer[i + offset] = '\0';
	return (write(1, buffer, i + offset));
}
/**
 * print_reverse - Prints a reverse string
 * @types: the list of args
 * @buffer: buffer aary to hnadle
 * @flags: calculate active flags
 * @width: gets width
 * @precision: presicion of specifque
 * @size: size specifier
 * Return: returns number of chars printed
 */

int print_reverse(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	char *st;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	st = va_arg(types, char *);
	if (st == NULL)
	{
		UNUSED(precision);

		st = ")Null(";
	}
	for (i = 0; st[i]; i++)
		;
	for (i = i - 1; i >= 0; i--)
	{
		char z = st[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/**
 * print_rot13string - Prints a str in rot13
 * @types: the list of args
 * @buffer: buffer aary to hnadle
 * @flags: calculate active flags
 * @width: gets width
 * @precision: presicion of specifque
 * @size: size specifier
 * Return: returns number of chars printed
 */

int print_rot13string(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	char *st;
	char x;
	unsigned int i, k;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	st = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (st == NULL)
		st = "(AHYY)";
	for (i = 0; st[i]; i++)
	{
		for (k = 0; in[k]; k++)
		{
			if (in[k] == st[i])
			{
				x = out[k];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[k])
		{
			x = st[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
