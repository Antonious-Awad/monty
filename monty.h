#ifndef MONTY_H
#define MONTY_H

/* To define type of dprintf */
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

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
void tokenize(char *buff, char **command);

/* Data Structures  */
void init_stack_data(FILE *stream);

#endif
