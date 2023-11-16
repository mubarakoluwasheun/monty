#include "monty.h"

/**
 * _pchar - Prints the character at the top of the stack
 * @head: A pointer to the top of the stack
 * @line_number: The current working line number of the Monty bytecodes file
 * Return: void
 */
void _pchar(stack_t **head, unsigned int line_number)
{
	int n;

	if (*head == 0)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		error = 1;
		return;
	}
	n = (*head)->n;

	if (!(n >= 32 && n <= 126))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		error = 1;
		return;
	}
	putchar(n);
	putchar('\n');
}
