#include "main.h"

/**
 * get_precision - gets the precision from the format string
 * @p: the format string
 * @params: the parameters struct
 * @ar_list: variadic pointer
 *
 * Return: new pointer
 */
char *get_precision(char *p, params_t *params, va_list ar_list)
{
	int d = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(ar_list, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			d = d * 10 + (*p++ - '0');
	}

	params->precision = d;
	return (p);
}
