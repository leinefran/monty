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
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = line_number; //will have to change to pull the right
	new->next = *head;    //element at the given line number
	new->prev = NULL;
	if (*head)
		(*head)->prev = new;
	*head = new;
}
