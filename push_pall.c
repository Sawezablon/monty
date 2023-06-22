#include "main.h"

/**
 * zabj_push - Opcode pushes an element to the stack
 *
 * @h: Indicates a pointer to the stack element
 * @args: Indicates a pointer to the characters
 *
 * @line_number: Indicates different operations in the stack
 */
void zabj_push(stack_t **h, char **args, unsigned int line_number)
{
	int n, *p_id;

	if (!byte_code(args[1]) || args[1] == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_monty(h);
		p_id = &code;
		*p_id = -1;
		return;
	}

	n = atoi(args[1]);
	if (code == 1)
	{
		add_node(h, n);
	}
	else if (code == 0)
	{
		add_node_end(h, n);
	}
}

#include "main.h"

/**
 * zabj_pall - Opcode prints all values on the stack , from  top to bottom
 *
 * @stack: Indicates a pointer to the stack
 *
 * @line_number: Indicates different operations in the stack
 */
void zabj_pall(stack_t **stack, unsigned int line_number)
{
	(void)(line_number);
	print_monty(stack);
}
