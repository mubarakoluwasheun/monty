#include "monty.h"

/**
 * _pall - Prints all linked list node data
 * @head: A pointer to the top of a stack_t linked list
 * @line_number: The current working line number of the Monty bytecodes file
 * Return: void
 */
void _pall(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;

	(void)line_number;

	if (*head == 0)
		return;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
