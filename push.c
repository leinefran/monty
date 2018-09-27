#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer to address of the stack
 * @line_number: number to be assigned to stack element
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int status;

	if (!stack)
		return;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	status = isnumber(get_value_at_node_index(line_number));
	if (status == -1)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		new->n = atoi(get_value_at_node_index(line_number));
	}

	new->next = *stack;    /* element at the given line number */
	new->prev = NULL;
	if (*stack == NULL)
	{
		*stack = new;
	}
	else
	{
		(*stack)->prev = new;
		*stack = new;
	}
}
