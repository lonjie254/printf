#include "main.h"

/**
 * _printf - prints and input into the std output
 * @format: array to print and check type
 *
 * Return: count of character printed
 */
int _printf(const char *format, ...)
{
  int sum = 0;
  va_list ar_list;
  char *p, *start;
  params_t params = PARAMS_INIT;

  va_start(ar_list, format);

  if (!format || (format[0] == '%' && !format[1]))/* checking for NULL character*/
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, ar_list);
		if (*p != '%')/*checking for the % specifier*/
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &params)) /* while char at p is flag char */
		{
			p++; /* next char */
		}
		p = get_width(p, &params, ar_list);
		p = get_precision(p, &params, ar_list);
		if (get_modifier(p, &params))
			p++;
		if (!check_specifier(p))
			sum += print_from_to(start, p,
				params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			sum += get_print_func(p, ap, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(ar_list);
	return (sum);
}
