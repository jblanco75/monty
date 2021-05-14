#include "monty.h"
/**
 * push - add a new node in a linked list.
 * @stack: stacker address of the linked list.
 * @line_number: number of lines in the monty file.
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
}
/**
 * pop - removes an element on the top of the stack.
 * @stack: linked list stacker address.
 * @line_number: line number from the file.
 * Return: nothing to return.
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't open an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		tmp = *stack;
		((*stack)->next)->prev = NULL;
		(*stack) = (*stack)->next;
		free(tmp);
	}
}
/**
 * swap - swap the top two elements of the stack.
 * @stack: linked list's stack address.
 * @line_number: line number from file.
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int iter;
	(void) line_number;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	iter = (*stack)->n;
	(*stack)->n = ((*stack)->next)->n;
	((*stack)->next)->n = iter;
}
