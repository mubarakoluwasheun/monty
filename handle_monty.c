#include "monty.h"

/**
 * check_token - Checks if a token is valid and has the necessary args or not
 * @head: The head of the linked list
 * @fp: File pointer
 * @line: The line to read
 * @token: Token to check
 * @line_number: The current working line number of a Monty bytecodes file
 * @mode: 0 if stack, 1 if queue
 * Return: void
 */
void check_token(stack_t **head, FILE *fp, char *line,
char *token, unsigned int line_number, int *mode)
{
	char *push_arg;
	void (*f)(stack_t **head, unsigned int line_number);

	if (!strncmp("push", token, 4) && (token[4] == '\0'))
	{
		push_arg = check_push_arg(token, line_number);
		if (push_arg != 0)
		{
			_push(head, line_number, push_arg, mode);
			if (error == 1)
			{
				free_list(head, fp, line);
				exit(EXIT_FAILURE);
			}
			return;
		}
		else
		{
			free_list(head, fp, line);
			exit(EXIT_FAILURE);
		}
	}
	f = get_function(token);
	if (!f)
	{
		opcode_fail(token, line_number);
		if (error == 1)
		{
			free_list(head, fp, line);
			exit(EXIT_FAILURE);
		}
	}
	f(head, line_number);
	if (error == 1)
	{
		free_list(head, fp, line);
		exit(EXIT_FAILURE);
	}
}

/**
 * get_function - Matches an opcode with its corresponding function
 * @token: Token to  match
 * Return: A pointer to the matching function
 */
void (*get_function(char *token))(stack_t **, unsigned int)
{
	int i;
	instruction_t ops[] = {
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};
	if (token[0] == '#')
		return (_nop);

	for (i = 0; ops[i].opcode; i++)
	{
		if (
				!strncmp(token, ops[i].opcode, strlen(ops[i].opcode)) &&
				(token[strlen(ops[i].opcode)] == '\0')
		   )
			return (ops[i].f);
	}
	return (NULL);
}

/**
 * opcode_fail - Prints malloc fail msg and unknown instruction err-msg
 * @token: The invalid command to display
 * @line_number: Line number in Monty bytecodes file where error occured
 * Return: void
 */
void opcode_fail(char *token, unsigned int line_number)
{
	int i, len;
	char *invalid_opcode;

	len = 0;
	while (token[len] != '\0' && token[len] != ' ' && token[len] != '\n')
		len++;
	invalid_opcode = malloc(sizeof(char) * (len));
	if (!invalid_opcode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		error = 1;
		return;
	}
	for (i = 0; i < len; i++)
		invalid_opcode[i] = token[i];
	fprintf(stderr, "L%d: unknown instruction %s\n",
			line_number, invalid_opcode);
	free(invalid_opcode);
	error = 1;
}
