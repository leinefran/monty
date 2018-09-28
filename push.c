#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer to address of the stack
 * @line_number: number to be assigned to stack element
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	char *argument;
	int status;

	if (!stack)
		return;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	argument = strtok(NULL, " ");
	status = isnumber(argument);
	if (status == -1)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		new->n = atoi(argument);
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
