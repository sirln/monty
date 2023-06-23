#include "monty.h"


/**
 * op_add - subtracts top element of stack from second element of stack
 * @stack: pointer to the stack
 * @line_number: line where opcode appears
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *element1 = *stack, *element2;

	if ((stack == NULL))
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	element2 = element1->next;
	if (element2 == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	element2->n = element2->n + element1->n;
	*stack = element2;
	element2->prev = NULL;
	free(element1);
}




/**
 * op_sub - subtracts top element of stack from second element of stack
 * @stack: pointer to the stack
 * @line_number: line where opcode appears
 */
void op_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *element1 = *stack, *element2;

	if ((stack == NULL))
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	element2 = element1->next;
	if (element2 == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	element2->n = element2->n - element1->n;
	*stack = element2;
	element2->prev = NULL;
	free(element1);
}



/**
 * op_mul - subtracts top element of stack from second element of stack
 * @stack: pointer to the stack
 * @line_number: line where opcode appears
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *element1 = *stack, *element2;

	if ((stack == NULL))
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	element2 = element1->next;
	if (element2 == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	element2->n = element2->n * element1->n;
	*stack = element2;
	element2->prev = NULL;
	free(element1);
}


/**
 * op_div - subtracts top element of stack from second element of stack
 * @stack: pointer to the stack
 * @line_number: line where opcode appears
 */
void op_div(stack_t **stack, unsigned int line_number)
{
	stack_t *element1 = *stack, *element2;

	if ((stack == NULL))
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	element2 = element1->next;
	if (element2 == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if (element1->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	element2->n = element2->n / element1->n;
	*stack = element2;
	element2->prev = NULL;
	free(element1);
}



/**
 * op_mod - subtracts top element of stack from second element of stack
 * @stack: pointer to the stack
 * @line_number: line where opcode appears
 */
void op_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *element1 = *stack, *element2;

	if ((stack == NULL))
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	element2 = element1->next;
	if (element2 == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if (element1->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	element2->n = element2->n % element1->n;
	*stack = element2;
	element2->prev = NULL;
	free(element1);
}
