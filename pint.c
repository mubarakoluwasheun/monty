#include "monty.h"

/**
 * _pint - Prints the value at the top of the stack
 * @head: A pointer to the top of the stack
 * @line_number: The current working line number of the monty bytecodes file
 * Return: void
 */
void _pint(stack_t **head, unsigned int line_number)
{
	if (head == 0 || *head == 0)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		error = 1;
		return;
	}
	printf("%d\n", (*head)->n);
}
