#include "monty.h"

/**
 * pint - print the first element of a singly linked list (stack)
 * @stack: address to pointer to top of the stack
 * @line_number: line_number, voided argument
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n",
			line_number, get_opcode_at_node_index(line_number));
		exit(EXIT_FAILURE);
	}
	printf("d\n", (*stack)->n);
}
