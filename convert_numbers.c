#include "main.h"

/**
 * print_hex - prints unsigned hex numbers in lowercase
 * @ar_list: variadic pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_hex(va_list ar_list, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ar_list, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ar_list, unsigned int);
	else
		l = (unsigned int)va_arg(ar_list, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtag_flag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * print_HEX - prints unsigned hex numbers in uppercase
 * @ar_list: variadic pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_HEX(va_list ar_list, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ar_list, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ar_list, unsigned int);
	else
		l = (unsigned int)va_arg(ar_list, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}
/**
 * print_binary - prints unsigned binary number
 * @ar_list: variadic pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_binary(va_list ar_list, params_t *params)
{
	unsigned int n = va_arg(ar_list, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, params);
	int c = 0;

	if (params->hashtag_flag && n)
		*--str = '0';
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * print_octal - prints unsigned octal numbers
 * @ar_list: variadic pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_octal(va_list ar_list, params_t *params)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ar_list, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ar_list, unsigned int);
	else
		l = (unsigned int)va_arg(ar_list, unsigned int);
	str = convert(l, 8, CONVERT_UNSIGNED, params);

	if (params->hashtag_flag && l)
		*--str = '0';
	params->unsign = 1;
	return (c += print_number(str, params));
}
