#include "main.h"

/**
 * print_char - prints character
 * @ar_list: variadic pointer
 * @params: the parameters struct
 * Return: number chars printed
 */
int print_char(va_list ar_list, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(ar_list, int);

	if (params->minus_flag)
		count += _putchar(ch);
	while (pad++ < params->width)
		count += _putchar(pad_char);
	if (!params->minus_flag)
		count += _putchar(ch);
	return (count);
}

/**
 * print_int - prints integer
 * @ar_list: variadic pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_int(va_list ar_list, params_t *params)
{
	long l;

	if (params->l_modifier)
		l = va_arg(ar_list, long);
	else if (params->h_modifier)
		l = (short int)va_arg(ar_list, int);
	else
		l = (int)va_arg(ar_list, int);
	return (print_number(convert(l, 10, 0, params), params));
}

/**
 * print_string - prints string
 * @ar_list: variadic pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_string(va_list ar_list, params_t *params)
{
	char *str = va_arg(ar_list, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)params;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	j = pad = _strlen(str);
	if (params->precision < pad)
		j = pad = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			count += _puts(str);
	}
	while (j++ < params->width)
		count += _putchar(pad_char);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				count += _putchar(*str++);
		else
			count += _puts(str);
	}
	return (count);
}
/**
 * print_percent - prints string
 * @ar_list: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_percent(va_list ar_list, params_t *params)
{
	(void)ar_list;
	(void)params;
	return (_putchar('%'));
}
