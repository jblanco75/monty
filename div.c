#include "monty.h"
/**
 * _div - divides top two elements of a linked list
 * @stack: top of the stack
 * @line_number: line number in the file
 * Return: void
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack, *tmp = NULL;
	int iter = 0;

	if (!stack || !*stack || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		freestack(*stack);
		exit(EXIT_FAILURE);
	}

	while (head != NULL)
	{
		head = head->next;
		++iter;
	}
	head = *stack;
	if (iter < 2 || head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		freestack(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		head->next->n  = head->next->n / head->n;
		tmp = head;
		head = head->next;
		free(tmp);
		head->prev = NULL;
		*stack = head;
	}
}
