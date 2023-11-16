#include "monty.h"

/**
 * _swap - Swap the top two elements of the stack
 * @head: A pointer to the top of the stack
 * @line_number: The current working line number of a Monty bytecodes file
 * Return: void
 */
void _swap(stack_t **head, unsigned int line_number)
{
	int n;

	if (*head == 0 || (*head)->next == 0)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		error = 1;
		return;
	}
	n = (*head)->n;
	(*head)->n = ((*head)->next)->n;
	((*head)->next)->n = n;
}
