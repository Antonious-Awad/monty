#include "monty.h"
/**
 * free_dbl_list - frees the doubly linked list (stack or queue)
 * @head: head node
 */

void free_dbl_list(stack_t *head)
{
	stack_t *curr = head;

	while (curr)
	{
		curr = curr->next;
		free(head);
		head = curr;
	}
}

/**
 * free_stack_data - frees stack variables
 */

void free_stack_data(void)
{
	free(STACK.buff);
	fclose(STACK.stream);
	free_dbl_list(STACK.top);
	free(STACK.command);
}
