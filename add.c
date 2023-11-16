#include "monty.h"

/**
 * _add - Adds the top 2 elements of the stack
 * @head: The head of the linked list
 * @line_number: The current line number of the bytecode file
 * Return: Nothing
 */
void _add(stack_t **head, unsigned int line_number)
{
	int sum = 0;

	if (*head == 0 || (*head)->next == 0)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		error = 1;
		return;
	}
	sum = ((*head)->n) + (((*head)->next)->n);
	_pop(head, line_number);
	(*head)->n = sum;
}
