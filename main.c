#include "monty.h"
/**
 * main - Entry Point
 * @argc: arg count
 * @argv: arg array
 * Return: EXIT_SUCCESS on success or EXIT_FAILURE if fails
 */
int main(int argc, char *argv[])
{
	FILE *f;
	char **tokens = NULL;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 1;


	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}	
	f = fopen(argv[1], "r");
	if (!f)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, f) != -1)
	{
		tokens = tokenize(line);
		if (!tokens)
		{
			fclose(f);
			free(tokens);
		}
		line_number++;
		sel_opc(*tokens);
		n = atoi(tokens[1]);
	}
	fclose(f);
	if (line)
		free(line);
	exit(EXIT_SUCCESS);
}
