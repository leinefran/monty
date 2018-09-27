#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * struct opcode_s
 * @op: opcode string
 * @arg: argument following opcode (optional for some opcodes)
 * @next: pointer to next node in list
 *
 * Description: singly linked list of Monty ByteCode instructions.
 * Each node contains one line of opcode instructions
 */
typedef struct opcode_s
{
	char *op;
	char *arg;
	struct opcode_s *next;
} opcode_t;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern opcode_t *head;

void check_arguments(int argc);
void file_open_status(int fd, char *argv[]);
void check_valid_instruc(char *s, unsigned int line_num);

void (*get_instruc_func(char *s, int *status))(stack_t **stack,
					       unsigned int line_number);
int isnumber(char *s);
int word_count(char *str);
char **split_string(char *str);
opcode_t *add_node_end(opcode_t **head, char **words);
void add_empty_node(opcode_t **head);
char *get_value_at_node_index(unsigned int line_number);
char *get_opcode_at_node_index(unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
