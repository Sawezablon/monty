#include "monty.h"

/**
 * zabj_rotr - Opcode rotates the stack to the bottom
 *
 * @stack: Indicates a pointer to the stack
 *
 * @line_number: Indicates different operations in the stack
 */
void zabj_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2, *last;

	(void)(line_number);

	if (*stack == NULL || _size(*stack) < 2)
		return;

	temp1 = *stack;
	last = *stack;

	for (; last->next != NULL; last = last->next)
		temp2 = last;

	temp2->next = NULL;
	last->next = temp1;
	(*stack) = last;
	last->prev = *stack;
}
