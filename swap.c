#include "main.h"

/**
 * zabj_swap - Opcode swaps top two elements of the stack
 *
 * @stack: Indicates a pointer to the stack
 *
 * @line_number: Indicates different operations in the stack
 */
void zabj_swap(stack_t **stack, unsigned int line_number)
{
	int *p_id;
	stack_t *temp, *temp2;

	(void)(line_number);

	if (*stack == NULL || _size(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_monty(stack);
		p_id = &code;
		*p_id = -1;
		return;
	}
	temp = *stack;
	*stack = (*stack)->next;
	temp2 = *stack;
	temp->next = temp2->next;
	temp2->next = temp;
	temp->prev = temp2;
	temp2->prev = NULL;
}
