#include "monty.h"
/**
 * _lifo - add node at the beginning
 * @stack: head of stack (linked list)
 * @new_stack: the node to add
 * Return:void
 */
void _lifo(stack_t **stack, stack_t new_stack)
{
	new_stack->prev = NULL;
	new_stack->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_stack;
	*stack = new_stack;
}
/**
 * _fifo - add node at the end
 * @stack: head to stack (linked list)
 * @new_stack: the node to add
 * Return:void
 */
void _fifo(stack_t **stack, stack_t new_stack)
{
	stack_t *copy = *stack;

	new_stack->next = NULL;
	if (!*stack)
	{
		new_node->prev = NULL;
		*stack = new_node;
	}
	else
	{
		while (copy->next)
			copy = copy->next;
		copy->next = new_node;
		new_node->prev = copy;
	}
}
