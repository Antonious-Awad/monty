#include "monty.h"
/**
 * add - adds top 2 elements of a stack
 * @stack: stack pointer
 * @line_number: number of line
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;
	stack_t *top, *below_top;

	if (!*stack || !(*stack)->next)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
		fclose(STACK.stream);
		free(STACK.buff);
		free_dbl_list(STACK.top);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	below_top = (*stack)->next;
	sum = top->n + below_top->n;
	below_top->n = sum;
	free(top);
	below_top->prev = NULL;
	STACK.top = below_top;
}
