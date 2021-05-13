#include "monty.h"
/**
 * push - add a new node in a linked list
 * @stack: header address of the linked list
 * @n: the push corresponding arg.
 * Return: nothing to return.
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
        (void)line_number;

	/*if (!stack)
	{
		fprintf(stderr, "Error: stack failed\n");
		exit(EXIT_FAILURE);
		}*/
		
	new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->prev = NULL;
	new->n = n;
	new->next = (*stack);

	if (*stack != NULL)
		(*stack)->prev = new;

	*stack = new;
}
/**
 * pall - print all node data in the linked list.
 * @stack: address of the linked list header.
 * @line_number: the number of lines of the monty file that we are treating.
 * Return: nothing to return.
 */

void pall(stack_t **stack, unsigned int line_number)
{

	stack_t *h = *stack;

	(void)line_number;

	if (*stack == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
/**
 * pint - prints the value on the top of the stack.
 * @stack: the address of the linked list header.
 * @line_number: number of lines wich we are reading.
 * Return: nothing to return.
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}
	printf("%d\n", (*stack)->n);
}
