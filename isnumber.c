#include "monty.h"

/**
 * isnumber - checks if the argv[2] is a number
 * @s: a pointer to the 3nd argument
 *
 * Return: 1 on success; otherwise, -1.
 */

int isnumber(char *s)
{
	unsigned int i;

	i = 0;

	if (!s)
		return (-1);

	if (*s == '-' || *s == '+')
	{
		s++;
		i++;
	}
	if (*s == '\0')
		return (-1);

	for (; i < strlen(s); i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (-1);
	}
	return (1);
}
