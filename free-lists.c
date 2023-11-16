#include "monty.h"

/**
 * free_list - Frees the linked list
 * @head: A pointer to the top of the stack
 * @fp: File pointer
 * @line: The line to read
 * Return: void
 */
void free_list(stack_t **head, FILE *fp, char *line)
{
	if (*head != 0)
	{
		while ((*head)->next)
		{
			(*head) = (*head)->next;
			free((*head)->prev);
		}
		free(*head);
	}
	fclose(fp);
	free(line);
}
