#include "monty.h"

/**
 * init_stack - initialize stack global variable
 * @file: file stream
 */

void init_stack(FILE *file)
{
	STACK.top = NULL;
	STACK.stream = file;
	STACK.buff = NULL;
	STACK.command = NULL;
}

/**
 * push - push to a stack
 * @stack: stack pointer
 * @line_number: number of line
 */

void push(stack_t **stack, unsigned int line_number)
{
	int n;
	char **command = STACK.command;
	stack_t *new;

	(void)stack;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_stack_data();
		exit(EXIT_FAILURE);
	}

	if (command[1] && is_digit(command[1]))
		n = atoi(command[1]);
	else
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		free_stack_data();
		free(new);
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->prev = NULL;
	if (!STACK.top)
	{
		new->next = NULL;
		STACK.top = new;
	}
	else
	{
		STACK.top->prev = new;
		new->next = STACK.top;
		STACK.top = new;
	}
}

/**
 * pint - returns the top element in the stack
 * @stack: stack pointer
 * @line_number: number of line
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		fclose(STACK.stream);
		free(STACK.buff);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - push to a stack
 * @stack: stack pointer
 * @line_number: number of line
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	if (!*stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		fclose(STACK.stream);
		free(STACK.buff);
		exit(EXIT_FAILURE);
	}

	curr = curr->next;
	free(*stack);
	STACK.top = curr;
}
