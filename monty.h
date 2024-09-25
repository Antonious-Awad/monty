#ifndef MONTY_H
#define MONTY_H

/* To define type of dprintf */
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct stack_vars - stack variables
 * @top: top item
 * @buff: buffer for each line per file
 * @command: array consisting of command and its argument
 * @stream: file stream
 */

typedef struct stack_vars
{
	stack_t *top;
	char *buff;
	char **command;
	FILE *stream;
} sv;

extern sv STACK;

/* File Operations */
FILE *read_file(char *name);

/* strings */
void tokenize(char *buff, char **command);
int is_digit(char *str);
void reset_command(char **command);

/* Data Structures  */
void init_stack(FILE *file);
void init_stack_data(FILE *stream);
void free_dbl_list(stack_t *head);
void free_stack_data(void);
void free_dbl_ptr(char **ptr);
void push(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);

/* Monty */
void run_command(int line);
void (*get_operation(char
												 *command))(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

#endif
