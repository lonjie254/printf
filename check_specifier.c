#include "main.h"

/**
 * check_specifier - search and return the correct function
 * @s: the format string
 * Return: return a function (if written correctly)
 */
int (*check_specifier(char *s))(va_list ar_list, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_int},
		{"i", print_int},
		{"b", print_binary},
		{"%", print_percent},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 *get_print_func - finds the format func
 * @s: the format string
 * @ar_list: argument pointer
 * @params: the parameters struct
 *
 * Return: the number of bytes printed
 */
int get_print_func(char *s, va_list ar_list, params_t *params)
{
	int (*f)(va_list, params_t *) = check_specifier(s);

	if (f)
		return (f(ar_list, params));
	return (0);
}

/**
 * get_flag - finds the flag func
 * @s: the format string
 * @params: the parameters struct
 *
 * Return: if flag was valid
 */
int get_flag(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->plus_flag = 1;
			break;
		case ' ':
			i = params->space_flag = 1;
			break;
		case '#':
			i = params->hashtag_flag = 1;
			break;
		case '-':
			i = params->minus_flag = 1;
			break;
		case '0':
			i = params->zero_flag = 1;
			break;
	}
	return (i);
}

/**
 * get_modifier - finds the modifier func
 * @s: the format string
 * @params: the parameters struct
 *
 * Return: if modifier was valid
 */
int get_modifier(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
	case 'h':
		i = params->h_modifier = 1;
		break;
	case 'l':
		i = params->l_modifier = 1;
		break;
	}
	return (i);
}

/**
 * get_width - gets the width from the format string
 * @s: the format string
 * @params: the parameters struct
 * @ar_list: argument pointer
 *
 * Return: new pointer
 */
char *get_width(char *s, params_t *params, va_list ar_list)
/* should this function use char**s and modify the pointer? */
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ar_list, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->width = d;
	return (s);
}
