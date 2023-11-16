#include "monty.h"

/**
 * _rotr - Rotates the stack to the bottom:
 *		   The last element of the stack becomes the top one,
 *		   and the top element of the stack becomes the second top one.
 * @head: A pointer to the top of the stack
 * @line_number: The current working line number of the Monty bytecodes file
 * Return: void
 */
void _rotr(stack_t **head, unsigned int line_number)
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
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	n = tmp->n;
	(tmp->prev)->next = 0;
	free(tmp);

	new = malloc(sizeof(stack_t));
	if (new == 0)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	(*head)->prev = new;
	new->next = *head;
	new->prev = NULL;
	*head = new;
}
