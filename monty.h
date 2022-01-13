#ifndef MONTY_H
#define MONTY_H
/* ###### LIBRARIES ####### */

#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/* ###### MACROS ####### */

#define BUFFSIZE 1024
#define LIFO 1
#define FIFO 2

/* ------ ERRORS --- */

#define ERROR_MALLOC 0
#define ERROR_FILE_USAGE 1
#define ERROR_OPEN_FILE 2
#define ERROR_UKNOWN_VALUE 3
#define ERROR_PUSH 4
#define ERROR_PINT 5
#define ERROR_POP 6
#define ERROR_SWAP 7

/* ###### STRUCTS ####### */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct inventory_s - a struct pointing to all pther structs for this project
 * @fname: filename from argv[1]
 * @stack: pointer to stack
 * @line: input line received from getline
 * @input: the input
 * @linenmbr: the line number
 * @file: the input file
 * @order: FIFO || LIFO
 */
typedef struct inventory_s
{
	char *fname;
	stack_t *stack;
	char *line;
	char **input;
	unsigned int linenmbr;
	FILE *file;
	int order;
} inventory_t;

/* ###### GLOBAL VARS ####### */

extern inventory_t *inventory;
inventory_t *inventory;

/* ###### FUNCTIONS ####### */

/* ----- HANDLERS ----- */
void error_handler(int e);
void (*monty_cmd_handler(void))(stack_t **stack, unsigned int line_number);
int areDigits(char *num);


int inventory_builder(void);
int line_parser(char *line);

/* ------ MEMORY MANAGMENT ---- */
void free_all(void);
void free_stack(void);

/* ----- NODE ADDING ------- */
void _fifo(stack_t **stack, stack_t *new_stack);
void _lifo(stack_t **stack, stack_t *new_stack);

/* --------- OPCODES ------*/
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint (stack_t **stack, unsigned int line_number);

#endif
