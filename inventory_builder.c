#include "monty.h"

/**
 * inventory_builder - builds global struct of most used vars
 * Return: EXIT_SUCCESS || EXIT_FAILURE
 */
int inventory_builder(void)
{
	inventory = malloc(sizeof(inventory_t));
	if (!inventory)
		error_handler(ERROR_MALLOC);

	inventory->input = malloc(sizeof(char *) * 3);
	if (!inventory->input)
	{
		free(inventory);
		error_handler(ERROR_MALLOC);
	}

	inventory->stack = NULL;
	inventory->line = NULL;
	inventory->linenmbr = 0;
	inventory->order = LIFO;

	return (EXIT_SUCCESS);
}
