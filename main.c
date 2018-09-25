#include "monty.h"

/**
 * main - interpreter for Monty ByteCodes files
 * @argc: number of command line arguments
 * @argv: argument vector
 *
 * Return: EXIT_SUCCESS upon success, else, EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	int fd;
	FILE *fpointer;
	size_t bufsize = 0;
	char *buf;
	char **words;
	opcode_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* gets file pointer from a file descriptor */
	fpointer = fdopen(fd, "r");
	/* build a singly linked list of Monty ByteCode instructions */
	while (getline(&buf, &bufsize, fpointer) != EOF)
	{
		words = split_string(buf);
		if (!words)
			continue;
		add_node_end(&head, words);
	}

	return (EXIT_SUCCESS);
}
