#include "main.h"

/**
 * add_node - add node on top of the list
 *
 * @q_s: pointer parameter
 * @n: parameter data
 * Return: New address of top node
 */
stack_t *add_node(stack_t **q_s, int n)
{
	int *z_code;
	stack_t *tmp = malloc(sizeof(stack_t));

	if (tmp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		z_code = &code;
		*z_code = -1;
		return (NULL);
	}

	tmp->n = n;
	tmp->next = (*q_s);
	tmp->prev = NULL;

	if ((*q_s) != NULL)
		(*q_s)->prev = tmp;

	(*q_s) = tmp;

	return (*q_s);
}

/**
 * add_node_end - add data at the end
 *
 * @q_s: parameter pointer
 * @n: parameter
 * Return: New address
 */
stack_t *add_node_end(stack_t **q_s, int n)
{
	int *z_code;
	stack_t *last = *q_s;
	stack_t *tmp = malloc(sizeof(stack_t));

	if (tmp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		z_code = &code;
		*z_code = -1;
		return (NULL);
	}

	tmp->n = n;
	tmp->next = NULL;

	if (*q_s == NULL)
	{
		tmp->prev = NULL;
		*q_s = tmp;
		return (*q_s);
	}

	while (last->next != NULL)
		last = last->next;

	last->next = tmp;
	tmp->prev = last;
	return (tmp);
}
