#include "monty.h"

int isnumber(char *s)
{
	unsigned int i;

	for (i = 0; i < strlen(s); i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (-1);
	}
	return (1);
}
