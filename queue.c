#include "monty.h"

/**
 * zabj_queue - Opcode sets the format of the data  to a queue(FIFO).
 *
 * @stack: Indicates a pointer to the stack
 *
 * @line_number: Indicates different operations in the stack
 */
void zabj_queue(stack_t **stack, unsigned int line_number)
{
	int *p_id;

	(void)(stack), (void)(line_number);
	p_id = &code;
	*p_id = 0;
}
