#include "monty.h"

/**
  *main - program start
  *
  *@argc: number of arguments passed
  *@argv: array of arguments
  *
  *Return: 0
  *
  */
int main(int argc, char **argv)
{
	stack_t *head = NULL;
	FILE *file;
	ssize_t char_read;
	char *content = NULL, *delimiters = "; \n\t\r";
	size_t size = 0;
	unsigned int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((char_read = getline(&content, &size, file)) != -1)
	{
		g_var.op_code_tokens = tokenize_string(content, delimiters);
		if (g_var.op_code_tokens[0] != NULL)
		{
			if (g_var.op_code_tokens[0][0] == '#')
			{
				free(g_var.op_code_tokens);
				continue;
			}
			else
				get_instruction(&head, line_number);
		}
		free(g_var.op_code_tokens);
		line_number++;
	}
	free(content);
	fclose(file);
	return (0);
}


/**
  * tokenize_string - splits a string
  *
  * @line: string to be split
  * @delim: delimiter
  *
  *Return: pointer to array of arrays
 */
char **tokenize_string(char *line, char *delim)
{
	char **tokens = NULL, *token = NULL;
	int i = 0;

	if (!line)
		return (NULL);

	tokens = malloc(sizeof(char *) * 1024);
	if (!tokens)
	{
		free(tokens);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, delim);
	while (token)
	{
		tokens[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
