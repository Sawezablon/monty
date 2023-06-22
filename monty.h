#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern int code;

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


char *_space(char *str);
char **stack_q(char *str);
int byte_code(char *String);
int _instruct(instruction_t *op, char **args);

void _opcode(char **args, stack_t **h, int *ltr);
void zabj_push(stack_t **h, char **args, unsigned int line_number);
void zabj_pall(stack_t **stack, unsigned int line_number);
void zabj_pint(stack_t **stack, unsigned int line_number);
void zabj_pop(stack_t **stack, unsigned int line_number);
void zabj_swap(stack_t **stack, unsigned int line_number);
void zabj_add(stack_t **stack, unsigned int line_number);
void zabj_nop(stack_t **stack, unsigned int line_number);
void zabj_sub(stack_t **stack, unsigned int line_number);
void zabj_div(stack_t **stack, unsigned int line_number);
void zabj_mul(stack_t **stack, unsigned int line_number);
void zabj_mod(stack_t **stack, unsigned int line_number);
void zabj_pchar(stack_t **stack, unsigned int line_number);
void zabj_pstr(stack_t **stack, unsigned int line_number);
void zabj_rotl(stack_t **stack, unsigned int line_number);
void zabj_rotr(stack_t **stack, unsigned int line_number);
void zabj_stack(stack_t **stack, unsigned int line_number);
void zabj_queue(stack_t **stack, unsigned int line_number);

stack_t *add_node(stack_t **head, int n);
void free_monty(stack_t **head);
stack_t *add_node_end(stack_t **head, int n);
void print_monty(stack_t **h);
size_t _size(stack_t *h);

#endif
