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
 * check_valid_instruc
 * @status: check return status of get_instruc_func
 *
 * exits with EXIT_FAILURE if appropriate
 */
void check_valid_instruc(int status, unsigned int line_number, char *opcode)
{
	if (status == -1)
	{
		fprintf(stderr, "L%ud: unknown instruction %s\n",
			line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
