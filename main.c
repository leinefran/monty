#include "monty.h"
stack_t *stack = NULL;

/**
 * main - interpreter for Monty ByteCodes files
 * @argc: number of command line arguments
 * @argv: argument vector
 *
 * Return: EXIT_SUCCESS upon success, else, EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	int fd, i;
	unsigned int line_number;
	FILE *fpointer;
	size_t bufsize = 0;
	char *buf = NULL;

	check_arguments(argc);
	fd = open(argv[1], O_RDONLY);
	file_open_status(fd, argv);

	/* gets file pointer from a file descriptor */
	fpointer = fdopen(fd, "r");
	/* read file line by line, call appropriate opcode */
	line_number = 1;
	while (getline(&buf, &bufsize, fpointer) != EOF)
	{
		i = strlen(buf);
		if (i > 0)
			buf[i - 1] = '\0';
		interpret_command(buf, line_number, fd, fpointer);
		line_number++;
	}
	close(fd);
	fclose(fpointer);
	free(buf);
	clear_stack(&stack);
	return (EXIT_SUCCESS);
}
