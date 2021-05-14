#include "monty.h"
/**
 * sel_opc - finds opc in array of structs
 * @func: operation to implement
 * @stack: top of linked list
 * Return: is 1 if successful and 0 if failed.
 */
void sel_opc(char *func, stack_t **stack)
{
	unsigned int index = 0;
	unsigned int line_number = 1;
	int checker = 0;

	instruction_t op_func[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"nop", nop}
	};

	for (index = 0; index < 6; index++)
	{
		checker = 0;
		if (strcmp(op_func[index].opcode, func) == 0)
		{
			checker = 1;
			op_func[index].f(stack, line_number);
			break;
		}
	}
	if (checker == 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, func);
		exit(EXIT_FAILURE);
	}
}
