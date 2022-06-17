#include "monty.h"
/**
 * add - Add two digits given by the user.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	if (*stack == NULL ||
		((*stack)->next == NULL && (*stack)->next->next == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp->next->n += temp->n;
	pop(stack, line_number);
}

/**
 * pall - Prints all the elements of the stack.
 *
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - Prints the top element of the stack.
 *
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
