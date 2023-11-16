#include "monty.h"

/**
 * _pop - Removes the top element of the stack
 * @head: A pointer to the top of the stack
 * @line_number: The current working line number of the monty bytecode file
 * Return: void
 */
void _pop(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = 0;

	if (*head == 0)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		error = 1;
		return;
	}
	if ((*head)->next == 0)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		tmp = *head;
		((*head)->next)->prev = NULL;
		(*head) = (*head)->next;
		free(tmp);
	}
}
