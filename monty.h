#ifndef MONTY_H_
#define MONTY_H_

/* Standard C Library Header Files */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* Global Variable Error Declaration */
extern int error;

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

/* Opcode Functions */
void _push(stack_t **stack, unsigned int line_number, char *str, int *mode);
void _pall(stack_t **head, unsigned int line_number);
void _pint(stack_t **head, unsigned int line_number);
void _pop(stack_t **head, unsigned int line_number);
void _swap(stack_t **head, unsigned int line_number);
void _add(stack_t **head, unsigned int line_number);
void _nop(stack_t **head, unsigned int line_number);
void _sub(stack_t **head, unsigned int line_number);
void _div(stack_t **head, unsigned int line_number);
void _mul(stack_t **head, unsigned int line_number);
void _mod(stack_t **head, unsigned int line_number);
void _pchar(stack_t **head, unsigned int line_number);
void _pstr(stack_t **head, unsigned int line_number);
void _rotl(stack_t **head, unsigned int line_number);
void _rotr(stack_t **head, unsigned int line_number);
void stack(stack_t **head, stack_t **new);
void queue(stack_t **head, stack_t **new);

/* Interpreter Functions */
char *check_push_arg(char *token, unsigned int line_number);
void line_tok(stack_t **head, FILE *fp, char *line, unsigned int line_number, int *mode);
void check_token(stack_t **head, FILE *fp, char *line,
char *token, unsigned int line_number, int *mode);
void (*get_function(char *token))(stack_t **, unsigned int);
int is_number(char *str, unsigned int line_number);
void free_list(stack_t **head, FILE *fp, char *line);
int check_mode(char *token, int *mode);

/* Error Message Functions */
void opcode_fail(char *token, unsigned int line_number);
void usage_error(unsigned int line_number);

#endif /* MONTY_H_ */
