#include "main.h"

/**
 * zabj_mul - Opcode multiplies second top element with top element
 *
 * @stack: Indicates a pointer to the stack
 *
 * @line_number: Indicates different operations in the stack
 */
void zabj_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int mul, *p_id;

	(void)(line_number);

	if (*stack == NULL || _size(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_monty(stack);
		p_id = &code;
		*p_id = -1;
		return;
	}
	temp = *stack;
	mul = (temp->next)->n * temp->n;
	(temp->next)->n = mul;
	zabj_pop(stack, line_number);
}
