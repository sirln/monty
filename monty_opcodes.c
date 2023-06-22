#include "monty.h"

/**
  *op_push - adds a new element at the top of the stack.
  *
  *@stack: pointer to pointer to top of the stack
  *@n: element to add to the stack
  *
  */
void op_push(stack_t **stack, size_t line_number)
{
	stack_t *new_stack;

	new_stack = malloc(sizeof(stack_t));
	if (!new_stack)
		return;

	new_stack->n = line_number;
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
  *op_pall - prints all the elements in a stack.
  *
  *@h: pointer to pointer to the top of the stack
  *
  */
void op_pall(stack_t **h)
{
	if (*h == NULL)
		return;
	while (*h)
	{
		printf("%i\n", (*h)->n);
		*h = (*h)->next;
	}
}

/**
 * op_pint - Prints the value at the top of the stack
 * @h: poniter to pointer to the top of stack
 * @count: the line number
**/
void op_pint(stack_t **h, unsigned int count)
{
	if (*h == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*h)->n);
}

/**
 * op_pop - Removes the top element of the stack
 * @h: pointer to pointer to the top of stack
 * @count: the line number
**/
void op_pop(stack_t **h, unsigned int count)
{
	stack_t *temp;

	if (*h == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		exit(EXIT_FAILURE);
	}
	temp = *h;
	*h = temp->next;
	free(temp);
}

/**
 * op_nop - dosen't do anything
 * @h: pointer to pointer to the top of stack
 * @count: the line number
**/
void op_nop(stack_t **h, unsigned int count)
{
	(void) count;
	(void) h;
}

/**
 * op_swap - swaps the top 2 elements of the stack
 * @stack: pointer to pointer to the top of stack
 * @line_number: the line number
*/
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	int len = 0, aux;

	h = *stack;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}
