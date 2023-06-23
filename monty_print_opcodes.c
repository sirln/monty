#include "monty.h"


/**
  *op_pall - prints all the elements of in a stack.
  *
  *@stack: pointer to pointer to the top of the stack
  *@line_number: element
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
 * @line_number: the line number
**/
void op_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	if ((*stack == NULL) || (stack == NULL))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", current->n);
}



/**
  * op_nop - dosen't do anything
  *
  * @stack: pointer to pointer to the top of stack
  * @line_number: the line number
  *
  */
void op_nop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
}

