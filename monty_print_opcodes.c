#include "monty.h"


/**
  *op_pall - prints all the elements of in a stack.
  *
  *@stack: pointer to pointer to the top of the stack
  *@line_number: opcode line number
  *
  */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	(void) line_number;
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}


/**
 * op_pint - Prints the value at the top of the stack
 * @stack: poniter to pointer to the top of stack
 * @line_number: opcode line number
**/
void op_pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
}



/**
  * op_nop - dosen't do anything
  *
  * @stack: pointer to pointer to the top of stack
  * @line_number: opcode line number
  *
  */
void op_nop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
}



/**
  * op_pchar - prints the character at the top of the stack
  *
  * @stack: pointer to pointer to the top of stack
  * @line_number: opcode line number
  *
  */
void op_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (!(*stack) || !stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if ((current->n > 32) && (current->n < 127))
		printf("%c\n", current->n);
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n",
			line_number);
		exit(EXIT_FAILURE);
	}
}

/**
  * op_pstr - prints the string starting at the top of the stack
  *
  * @stack: pointer to pointer to the top of stack
  * @line_number: opcode line number
  *
  */
void op_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current)
	{
		if ((current->n > 32) && (current->n < 127))
			printf("%c", current->n);
		else
			break;
		current = current->next;
	}
	printf("\n");
}
