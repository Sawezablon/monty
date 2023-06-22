#include "main.h"

/**
 * zabj_div - Opcode divides the second top element by top element
 *
 * @stack: Indicates a pointer to the stack
 *
 * @line_number: Indicates different operations in the stack
 */
void zabj_div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int div, *p_id;

	(void)(line_number);

	if (*stack == NULL || _size(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
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
	div = (temp->next)->n / temp->n;
	(temp->next)->n = div;
	zabj_pop(stack, line_number);
}
