#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer to address of the stack
 * @line_number: number to be assigned to stack element
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (!stack)
		return;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = atoi(get_value_at_node_index(line_number));
	if (new->n == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new->next = *stack;    /* element at the given line number */
	new->prev = NULL;
	printf("hi leine\n");
	if (*stack == NULL)
	{
		*stack = new;
	}
	else
	{
		(*stack)->prev = new;
		printf("hi jinji\n");
	}
}
