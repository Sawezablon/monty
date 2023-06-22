#include "monty.h"

/**
 * zabj_sub - Opcode subtracts top element from second element
 *
 * @stack: Indicates a pointer to the stack
 *
 * @line_number: Indicates different operations in the stack
 */
void zabj_sub(stack_t **stack, unsigned int line_number)
{
	int sub, *p_id;
	stack_t *temp;

	(void)(line_number);

	if (*stack == NULL || _size(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_monty(stack);
		p_id = &code;
		*p_id = -1;
		return;
	}
	temp = *stack;
	sub = (temp->next)->n - temp->n;
	(temp->next)->n = sub;
	zabj_pop(stack, line_number);
}
