#include "main.h"

/**
 * zabj_stack - Opcode sets the format of the data to a stack(LIFO).
 *
 * @stack: Indicates a pointer to the stack
 *
 * @line_number: Indicates different operations in the stack
 */
void zabj_stack(stack_t **stack, unsigned int line_number)
{
	int *p_id;

	(void)(stack), (void)(line_number);
	p_id = &code;
	*p_id = 1;
}
