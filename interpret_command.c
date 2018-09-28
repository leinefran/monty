#include "monty.h"

/**
 * interpret_command - interprets a string to see if it's a
 * Monty ByteCode command
 * @buf: buffer storing line to parse
 * @line_number: line number in bytecode instruction
 * @fd: file descriptor
 * @fpointer: file pointer
 */
void interpret_command(char *buf, unsigned int line_number,
		       int fd, FILE *fpointer)
{
	char *token;
	int status;

	token = strtok(buf, " ");
	if (token == NULL)
		return;
	status = check_valid_instruc(token, line_number, buf);
	if (status == -1)
	{
		close(fd);
		fclose(fpointer);
		exit(EXIT_FAILURE);
	}
	if (strcmp(token, "push") == 0)
	{
		push(&stack, line_number);
	}
	else
	{
		get_instruc_func(token)(&stack, line_number);
	}
}
