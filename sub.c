#include "monty.h"
/**
 * sub - substracts top two elements of a linked list
 * @stack: top of the stack
 * @line_number: line number in the file
 * Return: void
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack, *tmp = NULL;
	int iter = 0;

	if (!stack || !*stack || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
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
		head->next->n  = head->next->n - head->n;
		tmp = head;
		head = head->next;
		free(tmp);
		head->prev = NULL;
		*stack = head;
	}
}
