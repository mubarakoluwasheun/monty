#include "monty.h"

/**
 * _mul - Multiplies the second top element of the stack with the top element
 * @head: A pointer to the top of the stack
 * @line_number: The current line number of the month bytecode file
 * Return: void
 */
void _mul(stack_t **head, unsigned int line_number)
{
	int mul = 0;

	if (*head == 0 || (*head)->next == 0)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		error = 1;
		return;
	}
	mul = (((*head)->next)->n) * ((*head)->n);
	_pop(head, line_number);
	(*head)->n = mul;
}
