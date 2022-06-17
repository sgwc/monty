#include "monty.h"

/**
 * get_method - Gets the function pointer for the opcode
 * @method: The opcode to get the function pointer for
 * Return: The function pointer for the opcode
 */
void (*get_method(char *method))(stack_t **, unsigned int)
{
	int i = 0;
	instruction_t methods[] = {
			{"push", push},
			{"pall", pall},
			{"pint", pint},
			{"pop", pop},
			{"add", add},
			{"swap", swap},

			{NULL, NULL},
	};

	while (methods[i].opcode != NULL)
	{
		if (strcmp(methods[i].opcode, method) == 0)
			return (methods[i].f);
		i++;
	}
	return (NULL);
}
