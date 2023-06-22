#include "monty.h"

/**
 * zabj_add - Opcode adds top two elements of the stack
 *
 * @stack: Indicates a pointer to the stack element
 *
 * @line_number: Indicates different operations in the stack
 */
void zabj_add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int sum, *p_id;

	(void)(line_number);

	if (*stack == NULL || _size(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_monty(stack);
		p_id = &code;
		*p_id = -1;
		return;
	}
	temp = *stack;
	sum = temp->n + (temp->next)->n;
	(temp->next)->n = sum;
	zabj_pop(stack, line_number);
}
