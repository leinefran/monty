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
		fprintf(stderr, "L%ud: usage: push integer\n", line_number);
	}
	new->next = *head;    //element at the given line number
	new->prev = NULL;
	if (*head)
		(*head)->prev = new;
	*head = new;
}
