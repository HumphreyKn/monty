#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
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
 * struct global_s - hold line info
 * @m_code: pointer to file
 * @line: the line read
 *
 * Description: hold info about file
 */
typedef struct global_s
{
	FILE *m_code;
	char *line;
} glob_t;

extern int data;

/*Functions Used*/
/*New Element*/
stack_t *new_element(int element);

/*operations*/
int exec_op(stack_t **stack, char *argument, char *element, int n);
void push(stack_t **stack, unsigned int line);
void pall(stack_t **stack, unsigned int line);
void pop(stack_t **stack, unsigned int line);
void sub(stack_t **stack, unsigned int line);
void _div(stack_t **stack, unsigned int line);
void mul(stack_t **stack, unsigned int line);
void mod(stack_t **stack, unsigned int line);
void pchar(stack_t **stack, unsigned int line);
void pstr(stack_t **stack, unsigned int line);
void add(stack_t **stack, unsigned int line);
void free_stack(stack_t *stack);
void pint(stack_t **stack, unsigned int line);
void swap(stack_t **stack, unsigned int line);
void nop(stack_t **stack, unsigned int line);

/*Error Handling*/
void err_push(FILE *mon, char *line, stack_t *stack, int count);
void inv_inst(FILE *mon, char *line, stack_t *stack, char *argument, int count);

/*File Operations*/
void file_handler(char *argv);

#endif
