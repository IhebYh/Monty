#include "monty.h"
/**
 * _mod - computes the rest of the division of the top two elements of the stack
 * @stack: head of stack
 * @line_number: line number
 * Return: void
 */
void _mod(stack_t **stack, unsigned int line_number)
{
    int modulo;

    if(*stack == NULL || (*stack)->next == NULL)
        error_handler(ERROR_MOD);
    if ((*stack)->n == 0)
        error_handler(ERROR_DIV_ZERO);
    modulo = (*stack)->next->n / (*stack)->n;
    _pop(stack, line_number);
    (*stack)->n = modulo;
}
