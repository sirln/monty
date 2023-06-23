#include "monty.h"

/**
  *op_push - adds a new element at the top of the stack.
  *
  *@stack: pointer to pointer to top of the stack
  *@line_number: element to add to the stack
  *
  */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_stack;

	if (!(g_var.op_code_tokens[1]))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_stack = malloc(sizeof(stack_t));
	if (!new_stack)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_stack->n = atoi(g_var.op_code_tokens[1]);
	new_stack->prev = NULL;
	if (!*stack)
		new_stack->next = NULL;
	else
	{
		new_stack->next = *stack;
		(*stack)->prev = new_stack;
	}
	*stack = new_stack;
}


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
	if (!head)
	{
		return;
	}
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
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * op_pop - Removes the top element of the stack
 * @stack: pointer to pointer to the top of stack
 * @line_number: the line number
**/
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	printf("%d", (*stack)->n);
	*stack = temp->next;
	free(temp);
	printf("%d", (*stack)->n);
}

/**
 * op_nop - dosen't do anything
 * @stack: pointer to pointer to the top of stack
 * @line_number: the line number
**/
void op_nop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
}
