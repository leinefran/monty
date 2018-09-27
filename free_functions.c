#include "monty.h"

/**
 * free_opcode_list - frees singly linked list of opcode_t nodes
 * @head: address of pointer to head of linked list
 */
void free_opcode_list(opcode_t **head)
{
	opcode_t *tmp;

	tmp = *head;
	while (*head)
	{
		*head = (*head)->next;
		free(tmp);
		tmp = *head;
	}
}

/**
 * clear_stack - clears stack of doubly linked list
 * @h: address of pointer to top of stack
 */
void clear_stack(stack_t **h)
{
	while (*h)
		simple_pop(h);
}

/**
 * free_array - frees an array of words
 * @arr: pointer to first array of character pointers
 */
void free_array(char **arr)
{
	int i;
	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr[i]);
	free(arr);
	arr = NULL;

}
