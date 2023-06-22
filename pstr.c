#include "monty.h"

/**
 * zabj_pstr - Opcode prints string starting at the top of the stack
 *
 * @stack: Indicates a pointer to the stack
 *
 * @line_number: Indicates different operations in the stack
 */
void zabj_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)(line_number);

	if (*stack == NULL)
	{
		putchar('\n');
		return;
	}

	temp = *stack;
	while (temp != NULL)
	{
		if (temp->n <= 0 || temp->n > 127)
			break;
		putchar(temp->n);
		temp = temp->next;
	}
	putchar('\n');
}
