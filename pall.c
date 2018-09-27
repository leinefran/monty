#include "monty.h"

/**
 * pall - print all elements of stack
 * @stack: address to pointer to top of the stac
 * @line_number: line_number, voided argument
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;

	for (tmp = *stack; tmp; tmp = tmp->next)
		printf("%d\n", tmp->n);
}
