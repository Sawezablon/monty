#include "monty.h"

/**
 * zabj_pint - Opcodes prints values at the top of the stack
 *
 * @stack: Indicates a pointer to the stack
 *
 * @line_number: Indicates different operations in the stack
 */
void zabj_pint(stack_t **stack, unsigned int line_number)
{
	int *p_id;

	(void)(line_number);
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		p_id = &code;
		*p_id = -1;
		return;
	}

	printf("%d\n", (*stack)->n);
}
