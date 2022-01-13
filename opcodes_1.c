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
	if (inventory->order == 1)
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
		fprintf(stdout,"%d\n", copy->n);
}
/**
 * _pint - print the number of the head node
 * @stack : head of the stack
 * @line_number: line number
 * Return: void
*/
void _pint (stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (!*stack || !stack)
		error_handler(ERROR_PINT);

	fprintf(stdout,"%d\n", (*stack)->n);
}
/**
 * pop - removes the top element of the stack
 * @stack: head of stack
 * @line_number: line number
 * Return: void
*/
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *copy = *stack;
	(void)line_number;

	if (*stack == NULL)
		error_handler(ERROR_POP);
	copy = copy->next;
	free(*stack);
	*stack = copy;
	if (copy != NULL)
		copy->prev = NULL;
}
/**
 * _swap - swaps the top two elements of the stack
 * @stack: head of stack
 * @line_number: line number
 * Return: void
*/
void _swap(stack_t **stack, unsigned int line_number)
{
	int copy;
	(void)line_number;

	if (!stack || !*stack || !(*stack)->next)
		error_handler(ERROR_SWAP);

	copy = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = copy;
}
