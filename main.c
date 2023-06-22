#include "monty.h"

value_t value = {NULL, NULL, NULL};
/**
 * main - code interpretor for monty
 * @argc: no. of arguements passed 
 * @argv: file location for monty
 * Return: 0 on success
**/

int main(int argc, char **argv)
{
	FILE *file;
	char *content;
	size_t size = 0;
	ssize_t read = 1;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	value.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read > 0)
	{
		content = NULL;
		read = getline(&content, &size, file);
		value.content = content;
		count++;
		free(content);
	}
	fclose(file);	
	return (0);
}
