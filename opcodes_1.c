#include "monty.h"
/**
 * _push - adds a newnode to a stack_t list
 * @stack: headof stack
 * @line_number:line number
 * Return: void
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;
	char *num;
	(void)line_number;

	if (inventory->input[1] == NULL)
		error_handler(ERROR_PUSH);
	else
		num = inventory->input[1];
	if (areDigits(num) == 1)
	{
		new_node = malloc(sizeof(stack_t));
		if (new_node == NULL)
			error_handler(ERROR_MALLOC);
	}
	else
		error_handler(ERROR_PUSH);
	new_node->n = atoi(num);
	if (inventory->order == LIFO)
		_lifo(stack, new_node);
	else
		_fifo(stack, new_node);
}
/**
 * _pall - print all the values on the stack, starting from the top
 * @stack: head of the stack
 * @line_number: line number
 * Return: void
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *copy = *stack;
	(void)line_number;

	for (; copy; copy = copy->next)
		printf("%d\n", copy->n);
}
