#include "monty.h"

/**
 * _push - Pushes a new node to the linked list
 * @head: The head of the linked list
 * @line_number: The current line number of the Monty bytecode file
 * @arg: The matching argument to push
 * @mode: 0 if stack and 1 if queue
 * Return: void
 */
void _push(stack_t **head, unsigned int line_number, char *arg, int *mode)
{
	stack_t *new = NULL;
	int num = atoi(arg);

	(void)line_number;

	free(arg);
	new = malloc(sizeof(stack_t));
	if (new == 0)
	{
		fprintf(stderr, "Error: malloc failed\n");
		error = 1;
		return;
	}
	new->n = num;
	if (*mode == 0)
		stack(head, &new);
	else
		queue(head, &new);
}

/**
 * check_push_arg - Checks if a push command has an argument in its line
 * @token: Token matching the push line
 * @line_number: The current line number of the Monty bytecode file
 * Return: On SUCCESS, returns (arg) ie a pointer to the matching argument
 *	   On FAILURE returns (NULL)
 */
char *check_push_arg(char *token, unsigned int line_number)
{
	char *token2, *arg;
	int i, len;

	(void)token;

	token2 = strtok(NULL, " \n");

	while (token2 && token2[0] == ' ')
		token2 = strtok(NULL, " \n");

	if (!token2)
	{
		usage_error(line_number);
		return (NULL);
	}
	len = 0;
	while (token2[len] && token2[len] != '\n' && token2[len] != ' ')
		len++;

	arg = malloc(sizeof(char) * (len + 1));

	if (!arg)
	{
		usage_error(line_number);
		return (NULL);
	}
	for (i = 0; i < len; i++)
		arg[i] = token2[i];
	arg[i] = '\0';

	if (is_number(arg, line_number) == 1)
		return (NULL);
	return (arg);
}

/**
 * usage_error - Displays usage error
 * @line_number: The current line number of the Monty bytecode file
 */
void usage_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	error = 1;
}

/**
 * is_number - Checks if the pushed argument is a number of not
 * @str: The retrieved token after a found 'push' command
 * @line_number: The current line number of the Monty bytecode file
 * Return: int
 */
int is_number(char *str, unsigned int line_number)
{
	int i = 0;

	if (!(str[i] >= 48 && str[i] <= 57) && str[i] != '-')
	{
		usage_error(line_number);
		return (1);
	}
	else
		i++;

	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			i++;
		else
		{
			usage_error(line_number);
			return (1);
		}
	}
	return (0);
}
