#include "monty.h"

/**
 * pop - the opcode pop removes the top element of the stack
 * @stack: address to pointer to top of the stack
 * @line_number: line_number, voided argument
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	free(*stack);
	(*stack) = tmp;
	(*stack)->prev = NULL;
}
