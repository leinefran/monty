#include "monty.h"

/**
 * add - the opcode add adds the top two elements of the stack
 * @stack: address to pointer to top of the stack
 * @line_number: line_number, voided argument
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;
	stack_t *tmp;

	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	if (stack && count < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if (stack && count >= 2)
	{
		tmp = (*stack)->next;
		sum = (*stack)->n + tmp->n;
		tmp->n = sum;
		free(*stack);
		stack = tmp;
	}
}
