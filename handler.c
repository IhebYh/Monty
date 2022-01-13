#include "monty.h"
/**
 * error_handler - a function that handles errors
 * @e: error id
 * Return: void
 */
void error_handler(int e)
{
	unsigned int n;
	static char *const errors[] = {
		"Error: malloc failed\n", "USAGE: monty file\n",
		NULL, NULL,
		"usage: push integer\n", "can't pint, stack empty\n",
		"can't pop an empty stack\n", "can't swap, stack too short\n",
		"can't add, stack too short\n", "can't sub, stack too short\n",
		"can't div, stack too short\n", "division by zero\n",
		"can't mul, stack too short\n", "can't mod, stack too short\n",
		"can't pchar, stack empty\n", "can't pchar, value out of range\n"
	};

	if (inventory)
		n = inventory->linenmbr;

	if (e <= 1)
		dprintf(STDOUT_FILENO, "%s", errors[e]);
	else if (e == 2)
		dprintf(STDOUT_FILENO, "Error: Can't open file %s\n",
				inventory->fname);
	else if (e == 3)
		dprintf(STDOUT_FILENO, "L%u: unknown instruction %s\n", n,
				inventory->input[0]);
	else if (e >= 4)
		dprintf(STDOUT_FILENO, "L%u: %s", n, errors[e]);

	free_all();

	exit(EXIT_FAILURE);
}

/**
 * monty_cmd_handler - a function that handles monty commands
 * Return: function needed
 */
void (*monty_cmd_handler(void))(stack_t **stack, unsigned int line_number)
{
	char *input_cmd;
	instruction_t *i;
	instruction_t ins[] = {
		{"push", _push}, {"pall", _pall},
		{"pint",_pint},{"pop",_pop},
		{"swap",_swap},{"add",_add},
		{NULL, NULL}
	};

	i = ins;
	input_cmd = inventory->input[0];

	while (i->opcode && strncmp(i->opcode, input_cmd, strlen(input_cmd)))
		i++;

	if (!i->f)
		error_handler(ERROR_UKNOWN_VALUE);

	return (i->f);
}

/**
 * areDigits - checks if every character is a digit
 * @num: nmbr to check
 * Return: 0 or 1
 */
int areDigits(char *num)
{
	int i;

	for (i = 0; num[i] != '\0'; i++)
	{
		if (num[i] == '-' && i == 0)
			i++;
		if (isdigit(num[i]) == 0)
			return (0);
	}
	return (1);
}
