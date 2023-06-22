#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct arg_que - arguments
 * @vec: parameter
 * @ac: parameter
 * @line_number: parameter
 */
typedef struct arg_que
{
	char *vec;
	int ac;
	unsigned int line_number;
} arg_stack;

/**
 * struct data_s - extern data
 * @line: parameter
 * @words: parameter
 * @stack: parameter
 * @fptr: parameter
 * @qflag: parameter
 */
typedef struct data_s
{
	char *line;
	char **words;
	stack_t *stack;
	FILE *fptr;
	int qflag;
} data_t;

typedef stack_t dlistint_t;

extern data_t info;

#define DATA_INIT {NULL, NULL, NULL, NULL, 0}

#define SUB_FAIL "L%u: can't sub, stack too short\n"
#define DIV_FAIL "L%u: can't div, stack too short\n"
#define DIV_ZERO "L%u: division by zero\n"
#define MOD_FAIL "L%u: can't mod, stack too short\n"
#define PCHAR_FAIL "L%u: can't pchar, stack empty\n"
#define PCHAR_RANGE "L%u: can't pchar, value out of range\n"
#define USAGE "USAGE: monty file\n"
#define FILE_ERROR "Error: Can't open file %s\n"
#define MUL_FAIL "L%u: can't mul, stack too short\n"
#define PINT_FAIL "L%u: can't pint, stack empty\n"
#define POP_FAIL "L%u: can't pop an empty stack\n"
#define SWAP_FAIL "L%u: can't swap, stack too short\n"
#define ADD_FAIL "L%u: can't add, stack too short\n"
#define UNKNOWN "L%u: unknown instruction %s\n"
#define MALLOC_FAIL "Error: malloc failed\n"
#define PUSH_FAIL "L%u: usage: push integer\n"

void _opcode(arg_stack *str);
void (*get_func(char **parsed))(stack_t **, unsigned int);
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _release(int all);
size_t _length(const dlistint_t *h);
dlistint_t *_addnode(dlistint_t **head, const int n);
size_t _print(const dlistint_t *h);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
int _count(char *s);
char **_token(char *str);
void _deallocate(char **args);
void _stack(stack_t **stack, unsigned int line_number);
void _queue(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
int _delete(dlistint_t **head, unsigned int index);
dlistint_t *_get_node_index(dlistint_t *head, unsigned int index);
dlistint_t *_insert(dlistint_t **h, unsigned int idx, int n);
void _rotl(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
dlistint_t *_add_end(dlistint_t **head, const int n);
void _freelist(dlistint_t *head);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);

#endif
