#include "monty.h"
/**
 * line_parser - parse line/getline into input global var
 * @line: input line
 * Return: void
 */
int line_parser(char *line)
{
	char *delim, *s;
	int len, i;

	delim = "\n ";
    s = inventory->line;
	len = strlen(s);

	for (i = 0; s[i] == delim[0] || s[i] == delim[1]; i++)
		;
	if (i == len)
		return (EXIT_FAILURE);

	inventory->input[0] = strtok(line, delim);
	if (inventory->input[0][0] == '#')
		return (EXIT_FAILURE);
	inventory->input[1] = strtok(NULL, delim);

	return (EXIT_SUCCESS);
}
