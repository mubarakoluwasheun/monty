#include "monty.h"

/**
 * stack - Pushes a new node to the stack
 * @head: Pointer to the top of the stack
 * @new: The new node to push to the stack
 * Return: void
 */
void stack(stack_t **head, stack_t **new)
{
	if (*head == 0)
	{
		(*new)->prev = NULL;
		(*new)->next = NULL;
		*head = (*new);
	}
	else
	{
		(*head)->prev = *new;
		(*new)->next = *head;
		(*new)->prev = NULL;
		*head = *new;
	}
}

/**
 * queue - Pushes a new node to the queue
 * @head: The rear of the queue
 * @new: The new node to push to the queue
 * Return: Void
 */
void queue(stack_t **head, stack_t **new)
{
	stack_t *tmp;

	if (*head == 0)
	{
		(*new)->prev = NULL;
		(*new)->next = NULL;
		*head = (*new);
	}
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;

		tmp->next = *new;
		(*new)->next = NULL;
		(*new)->prev = tmp;
	}
}
