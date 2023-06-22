#include "monty.h"

/**
 * zabj_mod - Opcode computes rest of second top by top element of the stack
 *
 * @stack: Indicates a pointer to the stack
 * @line_number: Indicates different operations in the stack
 */
void zabj_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int mod, *p_id;

	(void)(line_number);

	if (*stack == NULL || _size(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_monty(stack);
		p_id = &code;
		*p_id = -1;
		return;
	}
	temp = *stack;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_monty(stack);
		p_id = &code;
		*p_id = -1;
		return;
	}
	mod = (temp->next)->n % temp->n;
	(temp->next)->n = mod;
	zabj_pop(stack, line_number);
}
