#include "monty.h"

/**
 * zabj_pchar - Opcode prints char at the top of the stack
 *
 * @stack: Indicates a pointer to the stack
 *
 * @line_number: Indicates different operations in the stack
 */
void zabj_pchar(stack_t **stack, unsigned int line_number)
{
	int *p_id;

	(void)(line_number);
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		p_id = &code;
		*p_id = -1;
		return;
	}

	if ((*stack)->n >= 0 && (*stack)->n <= 127)
	{
		printf("%c\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_monty(stack);
		p_id = &code;
		*p_id = -1;
		return;
	}
}
