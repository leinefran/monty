#include "monty.h"

/**
 * check_arguments - checks if correct number of command line arguments entered
 * @argc: argument count for command line arguments
 */
void check_arguments(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * file_open_status - checks if file was opened correctly
 * outputs error message if appropriate
 * @fd: file descriptor to check for error
 * @argv: the arguments passed to the function
 *
 * exits with EXIT_FAILURE if appropriate
 */
void file_open_status(int fd, char *argv[])
{
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
}

/**
 * check_valid_instruc - check if the instruction passed is valid or not
 * @status: check return status of get_instruc_func
 * @line_number: number of line count
 * @opcode: the instruction passed to the function
 *
 * exits with EXIT_FAILURE if appropriate
 */
void check_valid_instruc(char *s, unsigned int line_num)
{
	int i;
	char *valid_commands[] = {"push", "pall", "pint", "pop", NULL};

	for (i = 0; valid_commands[i]; i++)
	{
		if (strcmp(valid_commands[i], s) == 0)
			return;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_num, s);
	exit(EXIT_FAILURE);
}
