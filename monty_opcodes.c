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
	int x = 0;
	long value;

	if (g_var.op_code_tokens[1] == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	for (; g_var.op_code_tokens[1][x]; x++)
	{
		if (g_var.op_code_tokens[1][x] == '-' && x == 0)
			continue;
		if (g_var.op_code_tokens[1][x] < '0' || g_var.op_code_tokens[1][x] > '9')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	value = atoll(g_var.op_code_tokens[1]);
	if (value < INT_MIN || value > INT_MAX)
		exit(EXIT_FAILURE);
	new_stack = malloc(sizeof(stack_t));
	if (!new_stack)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/*new_stack->n = atoi(g_var.op_code_tokens[1]);*/
	new_stack->n = (int)value;
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
 * op_pop - Removes the top element of the stack
 * @stack: pointer to pointer to the top of stack
 * @line_number: the line number
**/
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);

}


/**
  * op_swap - adds the top 2 element of the stack
  *
  * @stack: pointer to pointer to the top of stack
  * @line_number: the line number
  *
  */
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int temp_data;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp_data = temp->n;
	temp->n = temp->next->n;
	temp->next->n = temp_data;
}


/**
  * op_add - adds the top 2 element of the stack
  *
  * @stack: pointer to pointer to the top of stack
  * @line_number: the line number
  *
  */
void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *element1 = *stack, *element2 = (*stack)->next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	element2->n = element1->n + element2->n;
	*stack = element2;
	element2->prev = NULL;
	free(element1);

}

