#include "monty.h"

/**
 * add_node_end - adds a new node at the end of a `list_t` linked list
 * @head: pointer to first node in linked list
 * @words: array of tokenized instructions.
 *
 * Return: address of the new element, or NULL if it failed
 */
opcode_t *add_node_end(opcode_t **head, char **words)
{
	opcode_t *new, *i;

	new = malloc(sizeof(opcode_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->op = words[0];
	if (words[1])
	{
		new->arg = words[1];
	}
	else
	{
		new->arg = NULL;
	}
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		for (i = *head; i->next != NULL; i = i->next)
			;
		i->next = new;
	}
	return (new);
}
