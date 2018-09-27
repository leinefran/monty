#include "monty.h"

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

	for (; i < strlen(s); i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (-1);
	}
	return (1);
}
