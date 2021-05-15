#include "monty.h"
/**
 * add - Adds top two elements of a linked list
 * @stack: top of the stack
 * @line_number: line number in the file
 * Return: void
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack, *tmp = NULL;
	int iter = 0;

	if (!stack || !*stack || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		freestack(*stack);
		exit(EXIT_FAILURE);
	}

	while (head != NULL)
	{
		head = head->next;
		++iter;
	}
	head = *stack;
	if (iter < 2)
	{
		freestack(*stack);
		*stack = NULL;
	}
	else
	{
		head->next->n  = head->n + head->next->n;
		tmp = head;
		head = head->next;
		free(tmp);
		head->prev = NULL;
		*stack = head;
	}
}
