#include "main.h"

/**
 * mul - multiplies the second top with the top element of the stack
 * @stack: pointer to the stack
 * @n: The line number
 *
 * Return: Nothong (void)
 */

void mul(stack_t **stack, unsigned int line)
{
	stack_t *last;

	if (line < 3)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	last = (*stack)->next;
	last->n *= (*stack)->n;
	pop(stack, line);
}
