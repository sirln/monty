#ifndef MONTY_HEADER_FILE
#define MONTY_HEADER_FILE

#define _POSIX_C_SOURCE 200809L


#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
  * struct global_var - storing a variable here
  *
  * @optoks: lines of opcode stored here
  *
  * Description: variable to be used in multiple functions
  *
  */
typedef struct global_var
{
	char **op_code_tokens;
} global_var_t;

/* global variable */
extern global_var_t g_var;

int main(int argc, char **agrv);


/* get opcodes */
/*void (*get_instruction(char *opcode, unsigned int l))(stack_t **s, unsigned int);*/
void get_instruction(stack_t **stack, unsigned int l);


/* opcodes */
void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);
void op_pint(stack_t **stack, unsigned int line_number);
void op_pop(stack_t **stack, unsigned int line_number);
void op_nop(stack_t **stack, unsigned int line_number);


/* tokenize file line */
char **tokenize_string(char *line, char *delim);

#endif
