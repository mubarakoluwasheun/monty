#include "monty.h"

/**
 * _div - Divides the second top element of the stack by the top element
 * @head: A pointer to the top of the stack
 * @line_number: The current line number of the bytecode file
 * Return: Nothing
 */
void _div(stack_t **head, unsigned int line_number)
{
	int div = 0;

	if (*head == 0 || (*head)->next == 0)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		error = 1;
		return;
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		error = 1;
		return;
	}
	div = (((*head)->next)->n) / ((*head)->n);
	_pop(head, line_number);
	(*head)->n = div;
}
