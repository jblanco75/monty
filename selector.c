#include "monty.h"
/**
 * sel_opc - finds opc in array of structs
 * @func: operation to implement
 * Return: is 1 if successful and 0 if failed.
 */
void *sel_opc(char *func)
{
	unsigned int index = 0;
	unsigned int line = 1;
	stack_t *stack = NULL;
	unsigned int line_number = 1;
	int checker = 0;
       

	instruction_t op_func[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};

	while (op_func[index].opcode)
	{
		
		if (strcmp(op_func[index].opcode, func) == 0)
		{
			checker = 1;
			op_func[index].f(&stack, line_number);
			break;
		}
		index++;
	}
	if (checker == 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, func);
		exit(EXIT_FAILURE);
	}
	return (NULL);
}
