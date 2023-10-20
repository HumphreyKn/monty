#include "monty.h"

int data = 0;

/**
 * main - Monty interpreter main function that get instructions from monty
 *		pytecode file and excute it on a stack.
 *
 * @argc: Count of arguments passed to the program.
 * @argv: List of the arguments passed.
 *
 * Return: SUCCESS if instruction is done Or FAILURE if:
 *	1. The user does not give any file or more than one argument.
 *	2. If you can’t malloc anymore.
 */

int main(int argc, char *argv[])
{
	if (argc == 2)
		file_handler(argv[1]);
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}

/**
 * file_handler - Reads the file, get the instructions
 * @argv: Arguments passed.
 *
 * Return: Nothing.
 */

void file_handler(char *argv)
{
	int count = 0, res = 0;
	char *arguments = NULL, *element = NULL;
	char delims[] = {' ', '\t', '\n'};
	stack_t *stack = NULL;
	size_t len = 0;
	glob_t global = {NULL, NULL};

	global.m_code = fopen(argv, "r");
	if (global.m_code)
	{
		while (getline(&global.line, &len, global.m_code) != -1)
		{
			count++;
			arguments = strtok(global.line, delims);
			if (arguments == NULL || *arguments == '#')
				continue;
			element = strtok(NULL, delims);
			res = exec_op(&stack, arguments, element, count);
			if (res == 1)
				inv_inst(global.m_code, global.line, stack, arguments, count);
			if (res == 2)
				err_push(global.m_code, global.line, stack, count);
		}
		fclose(global.m_code);
		free(global.line);
		free_stack(stack);
	}
	else
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
}

/**
 * exec_op - execute the stack operation.
 * @stack: stack.
 * @argument: name of the  operation
 * @element: element
 * @n: Line number to prtform the operation
 *
 * Return: 0 on sucess, 1 if not.
 */

int exec_op(stack_t **stack, char *argument, char *element, int n)
{
	int x = 0;
	instruction_t op[] = {
		{"push", push}, {"pall", pall}, {"pop", pop},
		{"add", add}, {"pint", pint}, {"nop", nop},
		{"swap", swap}, {"sub", sub}, {"div", _div},
		{"mul", mul}, {"mod", mod}, {"pchar", pchar},
		{"pstr", pstr}, {"swap", swap}, {NULL, NULL}
	};

	while (op[x].opcode)
	{
		if (!strcmp(argument, op[x].opcode))
		{
			if (!strcmp(argument, "push"))
			{
				data = atoi(element);
				if (data == 0 && element[0] != '0')
					return (2);
			}
			op[x].f(stack, (unsigned int)n);
			break;
		}
		x++;
	}
	if (!op[x].opcode)
		return (1);

	return (0);
}
