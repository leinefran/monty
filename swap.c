#include "monty.h"

/**
 * swap - the opcode swap swaps the top two elements of the stack
 * @stack: address to pointer to top of the stack
 * @line_number: line_number, voided argument
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *tmp_next;
	size_t count = 0;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (*stack != NULL)
		{
			count++;
			(*stack) = (*stack)->next;
		}
		if (stack && count < 2)
		{
			fprintf(stderr, "L%u: can't swap, stack too short\n",
				line_number);
			exit(EXIT_FAILURE);
		}
		if (stack && count >= 2)
		{
			tmp = (*stack);
			tmp_next = (*stack)->next;
			tmp->n = tmp_next->n;
			tmp_next->n = stack->n;
			(*stack) = tmp;
			(*stack)->next = tmp->next;
		}
	}
}
