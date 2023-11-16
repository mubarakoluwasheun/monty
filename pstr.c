#include "monty.h"

/**
 * _pstr - Prints the string starting at the top of the stack
 * @head: A pointer to the top of the stack
 * @line_number: The current working line number of the Monty bytecode file
 * Return: void
 */
void _pstr(stack_t **head, unsigned int line_number)
{
	int n;
	stack_t *tmp = *head;

	(void)line_number;

	if (*head == 0)
	{
		printf("\n");
		return;
	}
	while (tmp)
	{
		n = tmp->n;
		if (n && (n >= 32 && n <= 126))
			putchar(n);
		else if (n == 0 || (!(n >= 1 && n <= 127)))
		{
			break;
		}
		tmp = tmp->next;
	}
	putchar('\n');
}
