#include "monty.h"

/**
 * zabj_rotl - Opcode rotates the stack to the top
 *
 * @stack: Indicates a pointer to the stack
 *
 * @line_number: Indicates different operations in the stack
 */
void zabj_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2, *last;

	(void)(line_number);

	if (*stack == NULL || _size(*stack) < 2)
		return;

	temp1 = *stack;
	last = *stack;

	for (; last->next != NULL; last = last->next)
		;

	*stack = (*stack)->next;
	temp2 = *stack;
	temp2->prev = NULL;

	last->next = temp1;
	temp1->prev = last;
	temp1->next = NULL;
}
