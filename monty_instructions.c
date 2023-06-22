#include "monty.h"

/**
  *get_instructions - selects the correct function
  *     to perform the operation asked by user.
  *
  *@s: operator parameter
  *
  *Return: pointer to function
  *
  */

void get_instruction(stack_t **stack, unsigned int l)
{
	instruction_t inst[] = {
			{"push", op_push},
			{"pall", op_pall},
			{"pint", op_pint},
			{"pop", op_pop},
			/*{"swap", op_swap},
			{"nop", op_nop},
			{"add", op_add},
			{"sub", op_sub},
			{"mul", op_mul},
			{"div", op_div},
			{"mod", op_mod},
			*/
			{NULL, NULL}
	};
	int i = 0;

	while (inst[i].opcode != NULL)
	{
		if (strcmp(g_var.op_code_tokens[0], inst[i].opcode) == 0)
		{
			/*printf("%s\n", opcode);*/
			inst[i].f(stack, l);
			return;
		}
                i++;
        }
	fprintf(stderr, "L%u: unknown instruction %s\n", l, g_var.op_code_tokens[0]);
	exit(EXIT_FAILURE);
}
