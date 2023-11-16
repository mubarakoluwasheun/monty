#include "monty.h"

/**
 * _rotl - Rotates the stack to the top:
 *	   The top element of the stack becomes the last one,
 *	   and the second top element of the stack becomes the first one.
 * @head: A pointer to the top of the stack
 * @line_number: The current working line number of the Monty bytecode file
 * Return: void
 */
void _rotl(stack_t **head, unsigned int line_number)
{
	int n;
	stack_t *tmp, *new;

	if (*head == 0 || (*head)->next == 0)
		return;
	if (((*head)->next)->next == 0)
	{
		_swap(head, line_number);
		return;
	}
	n = (*head)->n;
	_pop(head, line_number);

	new = malloc(sizeof(stack_t));
	if (new == 0)
	{
		fprintf(stderr, "Error: malloc failed\n");
		error = 1;
		return;
	}
	new->n = n;
	new->next = NULL;
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}
