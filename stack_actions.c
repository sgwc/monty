#include "monty.h"
/**
 * push - pushes an element to the stack
 *
 * @stack: pointer to the top of the stack
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node1;
	(void)line_number;

	node1 = malloc(sizeof(stack_t));
	if (node1 == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	/*Validate if the number is a number*/
	node1->n = atoi(global_stack);
	node1->prev = NULL;
	node1->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = node1;
	*stack = node1;
}

/**
 * pop - Removes the top element of the stack
 *
 * @stack: Pointer to the top element of the stack
 * @line_number: Line number of the instruction
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
		free(*stack), *stack = NULL;
	else
	{
		stack_t *temp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
	}
}

/**
 * swap - Implement the swap opcode
 *
 * @stack: Pointer to the head of the stack
 * @line_number: Line number of the opcode
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	if (*stack == NULL ||
		((*stack)->next == NULL && (*stack)->next->next == NULL))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	temp->next = (*stack)->next;
	if ((*stack)->next != NULL)
		(*stack)->next->prev = temp;
	(*stack)->next = temp;
	temp->prev = *stack;
}
