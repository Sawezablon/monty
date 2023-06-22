#include "monty.h"

/**
 * _opcode - find opcodes and execute
 *
 * @tok: arguments
 * @struc: head node
 * @num: que number
 */
void _opcode(char **tok, stack_t **struc, int *num)
{
	int j, *z_code;
	instruction_t opc[] = {
		{"pint", zabj_pint}, {"pall", zabj_pall},
		{"pop", zabj_pop}, {"swap", zabj_swap},
		{"add", zabj_add}, {"sub", zabj_sub},
		{"mul", zabj_mul}, {"div", zabj_div},
		{"mod", zabj_mod}, {"nop", zabj_nop},
		{"pchar", zabj_pchar}, {"pstr", zabj_pstr},
		{"rotl", zabj_rotl}, {"rotr", zabj_rotr},
		{"stack", zabj_stack}, {"queue", zabj_queue},
		{NULL, NULL}};

	if (strcmp("push", tok[0]) == 0)
	{
		zabj_push(struc, tok, *num);
	}
	else if (_instruct(opc, tok))
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", *num, tok[0]);
		free_monty(struc);
		z_code = &code;
		*z_code = -1;
		return;
	}
	else
	{
		j = 0;
		while (opc[j].opcode)
		{
			if (strcmp(opc[j].opcode, tok[0]) == 0)
			{
				(opc[j].f)(struc, *num);
				break;
			}
			j++;
		}
	}
}
