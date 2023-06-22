#include "monty.h"

int code = 1;

/**
 * main -entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: Always 0 (Success)
 */
int main(int argc, char **argv)
{
	stack_t *ptr;
	FILE *file;
	char *line = NULL, *insert = NULL, que[1024], **tok;
	int que_no = 0, *num;

	ptr = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	num = &que_no;
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	else
	{
		for (; fgets(que, sizeof(que), file) != NULL; ++*num)
		{
			if (que[strlen(que) - 1] == '\n')
				que[strlen(que) - 1] = '\0';
			line = que;
			insert = _space(line);
			if (insert[0] == '\0' || insert[0] == '#' || insert[0] == '\n')
				continue;
			tok = stack_q(insert);
			_opcode(tok, &ptr, num);
			free(tok);
			if (code == -1)
				break;
		}
	}
	fclose(file);
	if (code == -1)
		exit(EXIT_FAILURE);
	free_monty(&ptr);
	return (0);
}

/**
 * _instruct - Check instruction
 *
 * @opc: opcode
 * @tok: arguments
 * Return: 1 or 0
 */
int _instruct(instruction_t *opc, char **tok)
{
	int j = 0;

	while (opc[j].opcode)
	{
		if (strcmp(opc[j].opcode, tok[0]) == 0)
			return (0);
		j++;
	}

	return (1);
}

/**
 * print_monty - print elements
 *
 * @struc: parameter node
 */
void print_monty(stack_t **struc)
{
	stack_t *tmp;

	if (*struc == NULL || struc == NULL)
		return;

	tmp = *struc;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * free_monty - free elements
 *
 * @head: parameter
 */
void free_monty(stack_t **head)
{
	stack_t *current = *head;
	stack_t *next;

	if (*head == NULL)
		return;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
