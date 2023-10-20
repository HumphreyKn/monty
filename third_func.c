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

/**
 * pchar - prints the char at the top of the stack
 * @stack: pointer to the stack
 * @n: line number.
 *
 * Return: Nothing (void)
 */

void pchar(stack_t **stack, unsigned int line)
{
	int x;

	if (line < 2)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line);
		exit(EXIT_FAILURE);
	}

	x = (*stack)->n;

	if ((x >= 65 && x <= 90) || (x >= 97 && x <= 122))
		printf("%c\n", (char)x);
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line);
		exit(EXIT_FAILURE);
	}
}


/**
 * _div - Divides the second top top element of the stack
 * @stack: pointer to the stack
 * @n: line number
 *
 * Return: Nothing
 */

void _div(stack_t **stack, unsigned int line)
{
	stack_t *last;

	if (line < 3)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line);
		exit(EXIT_FAILURE);
	}

	last = (*stack)->next;
	last->n /= (*stack)->n;
	pop(stack, line);
}

/**
 * mod - computes  division of the second toptop element
 * @stack: A pointer to the stack.
 * @n: The line number.
 *
 * Return: Nothing
 */

void mod(stack_t **stack, unsigned int line)
{
	stack_t *last;

	if (line < 3)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line);
		exit(EXIT_FAILURE);
	}

	last = (*stack)->next;
	last->n %= (*stack)->n;
	pop(stack, line);
}

/**
 * nop - Does nothing
 * @stack: the stack
 * @n: the line number
 *
 * Return: Nothing (void)
 */

void nop(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;
}
