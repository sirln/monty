#include "monty.h"

/**
  *get_instruction - selects the correct function
  *     to perform the operation asked by user.
  *
  *@stack: stack structure
  *@l: line number of file being read
  *
  */

void get_instruction(stack_t **stack, unsigned int l)
{
	instruction_t inst[] = {
			{"push", op_push},
			{"pall", op_pall},
			{"pint", op_pint},
			{"pop", op_pop},
			{"swap", op_swap},
			{"add", op_add},
			{"nop", op_nop},
			{"sub", op_sub},
			{"mul", op_mul},
			{"div", op_div},
			{"mod", op_mod},
			{"pchar", op_pchar},
			{"pstr", op_pstr},
			{"stack", op_stack},
			{"queue", op_queue},
			{NULL, NULL}
	};
	int i = 0;

	while (inst[i].opcode != NULL)
	{
		if (strcmp(g_var.op_code_tokens[0], inst[i].opcode) == 0)
		{
			inst[i].f(stack, l);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", l, g_var.op_code_tokens[0]);
	exit(EXIT_FAILURE);
}
