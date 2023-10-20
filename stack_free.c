#include "monty.h"

/**
 * free_stack - Frees the stack.
 * @stack: pointer to the list.
 *
 * Return: Nothing (void)
 */

void free_stack(stack_t *stack)
{
	stack_t *tmp = stack;

	if (tmp != NULL)
	{
		free_stack(tmp->next);
		free(tmp);
	}
}
