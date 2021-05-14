#include "monty.h"
/**
 * freestack - free a double lk list
 * @stack: top of the linked list
 * Return: Nothing
 */
void freestack(stack_t *stack)
{
	stack_t *lib;

	if (stack == NULL)
		return;

	while (stack != NULL)
	{
		lib = stack;
		stack = stack->next;
		free(lib);
	}
}
