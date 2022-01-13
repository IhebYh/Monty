#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 * @stack: headof stack
 * @line_number:line number
 * Return: void
 */
void _add(stack_t **stack, unsigned int line_number)
{
    int sum;

    if(*stack == NULL || (*stack)->next == NULL)
        error_handler(ERROR_ADD);
    sum = (*stack)->n + (*stack)->next->n;
    _pop(stack, line_number);
    (*stack)->n = sum;
}
