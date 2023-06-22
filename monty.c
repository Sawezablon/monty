#include "monty.h"

/**
 * _space - remove spaces from ch
 *
 * @ch: input string
 * Return: string
 */
char *_space(char *ch)
{
	for (; *ch == ' '; ch++)
		;
	return (ch);
}


/**
 * stack_q - function that creates array
 *
 * @ch: argument parameter
 * Return: pointer array
 */
char **stack_q(char *ch)
{
	int j, *z_code;
	char **str, *tok;

	str = malloc(sizeof(char *) * 64);
	if (str == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		z_code = &code;
		*z_code = -1;
		return (NULL);
	}

	tok = strtok(ch, " ");
	j = 0;
	while (tok != NULL)
	{
		str[j] = tok;
		tok = strtok(NULL, " ");
		j++;
	}
	str[j] = NULL;

	return (str);
}

/**
 * byte_code - confirm if its a number
 *
 * @S: parameter
 * Return: 0
 */
int byte_code(char *S)
{
	size_t i;

	if (S == NULL)
		return (0);
	if (S[0] == '-')
	{
		i = 1;
		while (i < strlen(S))
		{
			if ((S[i] < '0') || (S[i] > '9'))
				return (0);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < strlen(S))
		{
			if ((S[i] < '0') || (S[i] > '0' + 9))
				return (0);
			i++;
		}
	}

	return (1);
}

/**
 * _size - stack size
 *
 * @sq: parameter
 * Return: size of stack
 */
size_t _size(stack_t *sq)
{
	stack_t *tmp;
	size_t i;

	if (sq == NULL)
		return (0);

	i = 0;
	tmp = sq;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
