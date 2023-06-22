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
		return (NULL);

	new_stack->n = line_number;
	new_list->prev = NULL;
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
  *@h: pointer to pointer to the top of the stack
  *
  */
void op_pall(stack_t **h)
{
        if (!*h)
                return (0);
        while (*h)
        {
                printf("%i\n", (*h)->n);
                *h = (*h)->next;
        }
}
