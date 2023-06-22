#include "monty.h"

/**
 * zabj_pop - Opcode removes the top element of the stack
 *
 * @stack: Indicates a pointer of stack
 *
 * @line_number: Indicates different operations in the stack
 */
void zabj_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int *p_id;

	(void)(line_number);
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		p_id = &code;
		*p_id = -1;
		return;
	}

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
