#include "main.h"

/**
 * check_specifier - search and return the correct function
 * @s: array to check
 * Return: return a function (if written correctly)
 */
int (*check_specifier(char s))(va_list)
{
	op_t ops[] = {
		{"c", print_c},
		{"s", print_s},
		{"d", print_d},
		{"i", print_i},
		{"b", print_b},
		{"%", print_percent},
		{NULL, NULL}};

	int i;

	for (i = 0; ops[i].c != NULL; i++)
	{
		if (*ops[i].c == s)
			return (ops[i].f);
	}
	return (NULL);

}
