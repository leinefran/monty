#include "monty.h"

/**
 * mul - multiplies the second top element of the stack
 * with the top element of the stack
 * @stack: address to pointer of top of the stack
 * @line_number: line number of monty bytecode file
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
        int value, len = 0;

        for (tmp = *stack; tmp; tmp = tmp->next)
                len++;
        if (len < 2)
        {
                fprintf(stderr, "L%u: can't mul, stack too short\n",
                        line_number);
                clear_stack(stack);
                exit(EXIT_FAILURE);
	}
	value = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n *= value;
}
