#include "monty.h"

/**
 * main - interpreter for Monty ByteCodes files
 * @argc: number of command line arguments
 * @argv: argument vector
 *
 * Return: EXIT_SUCCESS upon success, else, EXIT_FAILURE
 */
opcode_t *head = NULL;
int main(int argc, char *argv[])
{
	int fd, i, status;
	unsigned int line_num, blank_lines;
	FILE *fpointer;
	size_t bufsize = 0;
	char *buf;
	char **words = NULL;
	stack_t *stack = NULL;
/*	stack_t *tmp; */

	check_arguments(argc);

	fd = open(argv[1], O_RDONLY);
	file_open_status(fd, argv);

	/* gets file pointer from a file descriptor */
	fpointer = fdopen(fd, "r");
	/* build a singly linked list of Monty ByteCode instructions */
	while (getline(&buf, &bufsize, fpointer) != EOF)
	{
		i = strlen(buf);
		if (i > 0)
			buf[i - 1] = '\0';
		words = split_string(buf);
		if (!words)
			continue;
		add_node_end(&head, words);
	}
	free(words);

	close(fd);
	fclose(fpointer);

	fd = open(argv[1], O_RDONLY);
	file_open_status(fd, argv);
	fpointer = fdopen(fd, "r");

	line_num = 1, blank_lines = 0;
	/* read file line by line, call appropriate opcode */
	while (getline(&buf, &bufsize, fpointer) != EOF)
        {
                i = strlen(buf);
                if (i > 0)
                        buf[i - 1] = '\0';
                words = split_string(buf);
                if (!words)
		{
			line_num++;
			blank_lines++;
                        continue;
		}
		get_instruc_func(words[0], &status)(&stack,
						    line_num - blank_lines);
/*		printf("%d\n", status);
		is_valid = check_valid_instruc(status, line_num, words[0]);*/
		if (status == -1)
		{
			fprintf(stderr, "L%ud: unknown instruction %s\n",
				line_num, words[0]);
			exit(EXIT_FAILURE);
		}

		line_num++;
	}

/*	for (tmp = stack; tmp; tmp = tmp->next)
	printf("stack value is %d\n", tmp->n); */

	return (EXIT_SUCCESS);
}
