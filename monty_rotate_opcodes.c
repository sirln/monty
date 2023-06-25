#include "monty.h"

/**
 * op_rotl - rotates the first element to the bottom and the last to the top
 *
 * @stack: pointer to the pointer to the top of the stack
 * @line_number: opcode line number
 */
void op_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *aux1 = NULL;
	stack_t *aux2 = NULL;
	(void)line_number;

	if (*stack == NULL)
		return;

	if ((*stack)->next == NULL)
		return;

	aux1 = (*stack)->next;
	aux2 = *stack;

	for (; aux2->next != NULL; aux2 = aux2->next)
		;

	aux1->prev = NULL;
	aux2->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = aux2;
	*stack = aux1;
}

/**
 * op_rotr - rotates the stack at the bottom
 *
 * @stack: pointer to pointer to the top of the stack
 * @line_number: opcode line number
 */
void op_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = NULL;
	(void)line_number;

	if (*stack == NULL)
		return;

	if ((*stack)->next == NULL)
		return;

	aux = *stack;

	for (; aux->next != NULL; aux = aux->next)
		;

	aux->prev->next = NULL;
	aux->next = *stack;
	aux->prev = NULL;
	(*stack)->prev = aux;
	*stack = aux;
}
