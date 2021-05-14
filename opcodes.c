#include "monty.h"
/**
 * _push - add a new node in a linked list.
 * @stack: stacker address of the linked list.
 * @num: push the corresponding argument.
 * @line_number: the number of lines in the monty file.
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed, in line %d\n", line_number);
		exit(EXIT_FAILURE);
	}
	new->n = num;
	new->prev = NULL;
	new->next = NULL;

	if (*stack)
	{
		(*stack)->prev = new;
		new->next = *stack;
	}
	*stack = new;
	printf("%d\n", (*stack)->n);
}
/**
 * pall - print all node data in the linked list.
 * @stack: address of the linked list header.
 * @line_number: the number of lines of the monty file that we are treating.
 * Return: nothing to return.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	(void)line_number;

	if (head == NULL)
		printf("Hola mundo\n");

	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
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
