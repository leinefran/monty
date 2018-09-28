#include "monty.h"

/**
 * clear_stack - clears stack of doubly linked list
 * @h: address of pointer to top of stack
 */
void clear_stack(stack_t **h)
{
	while (*h)
		simple_pop(h);
}
