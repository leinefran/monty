#include "monty.h"

/**
 * get_value_at_node_index - returns the value of node at line number.
 * @line_number: starts at 1.
 *
 * Return: argument value of opcode_t at line number in byte code instructions.
 */
char *get_value_at_node_index(unsigned int line_number)
{
	unsigned int index, i;
	opcode_t *tmp = head;

	index = line_number - 1;

	for (i = 0; i < index && tmp; i++)
	{
		tmp = tmp->next;
	}
	return (tmp->arg);
}
