#include "monty.h"

/**
 * _sub - Substracts the top element of the stack from the second element
 * @head: A pointer to the top of the stack
 * @line_number: The current working line number of the Monty bytecodes file
 * Return: void
 */
void _sub(stack_t **head, unsigned int line_number)
{
	int sub = 0;

	if (*head == 0 || (*head)->next == 0)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		error = 1;
		return;
	}
	sub = (((*head)->next)->n) - ((*head)->n);
	_pop(head, line_number);
	(*head)->n = sub;
}
