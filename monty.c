#include "monty.h"

/**
 * main - entry point
 * @argv: char
 * @argc: int
 * Return: int
 */
int main(int argc, char *argv[])
{
	size_t n;
	void (*exec)(stack_t **stack, unsigned int line_number);

	inventory = NULL;
	if (argc != 2)
		error_handler(ERROR_FILE_USAGE);

	inventory_builder();

	inventory->fname = argv[1];
	inventory->file = fopen(inventory->fname, "r");
	if (inventory->file == NULL)
		error_handler(ERROR_OPEN_FILE);

	while (getline(&inventory->line, &n, inventory->file) > 0)
	{
		inventory->linenmbr++;
		if (line_parser(inventory->line) == EXIT_FAILURE)
			continue;
		exec = monty_cmd_handler();
		exec(&inventory->stack, inventory->linenmbr);
	}
	/* TODO : FREE EVERYTHING */
	return (EXIT_SUCCESS);
}
