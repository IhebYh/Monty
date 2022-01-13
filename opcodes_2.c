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
/**
 * _nop - doesn't do anything
 * @stack: headof stack
 * @line_number:line number
 * Return: void
 */
void _nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}
/**
 * _sub - subtracts the top two elements of the stack
 * @stack: headof stack
 * @line_number:line number
 * Return: void
 */
void _sub(stack_t **stack, unsigned int line_number)
{
    int diff;

    if(*stack == NULL || (*stack)->next == NULL)
        error_handler(ERROR_SUB);
    diff = (*stack)->next->n - (*stack)->n;
    _pop(stack, line_number);
    (*stack)->n = diff;
}
/**
 * _div - divides the top two elements of the stack
 * @stack: headof stack
 * @line_number:line number
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
    int quotient;

    if(*stack == NULL || (*stack)->next == NULL)
        error_handler(ERROR_DIV);
    if ((*stack)->n == 0)
        error_handler(ERROR_DIV_ZERO);
    quotient = (*stack)->next->n / (*stack)->n;
    _pop(stack, line_number);
    (*stack)->n = quotient;
}
/**
 * _mul - multiplies the top two elements of the stack
 * @stack: headof stack
 * @line_number:line number
 * Return: void
 */
void _mul(stack_t **stack, unsigned int line_number)
{
    int product;

    if(*stack == NULL || (*stack)->next == NULL)
        error_handler(ERROR_MUL);
    product = (*stack)->n * (*stack)->next->n;
    _pop(stack, line_number);
    (*stack)->n = product;
}
