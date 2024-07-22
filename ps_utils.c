/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:04:19 by djelacik          #+#    #+#             */
/*   Updated: 2024/07/22 21:25:55 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	add_node(t_stack **head, t_info *info, int value)
{
	t_stack	*new_node;
	t_stack	*current;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
	info->size++;
}

void	print_stacks(t_stacks *stacks)
{
	t_stack	*current;
	
	printf("Stack A:\n");
	current = stacks->a;
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	printf("Stack B:\n");
	current = stacks->b;
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	printf("\n");
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

int	validator(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*current;

	temp = *stack;
	current = temp;
	while (current && current->next != NULL)
	{
		temp = current->next;
		while (temp)
		{
			if (temp->value == current->value)
				return (1);
			temp = temp->next;
		}
		current = current->next;
	}
	return (0);
}

void	error_exit(t_stack **stack)
{
	write(STDOUT_FILENO, "Error\n", 6);
	free_stack(stack);
	exit (1);
}

int	get_stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int	last_value(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	if (!stack)
		return (0);
	while (current != NULL)
		current = current->next;
	return (current->value);
}

int	is_smallest(t_stacks *stacks)
{
	t_stack	*current;
	int	smallest;
	
	current = stacks->b;
	smallest = current->value;
	while (current != NULL)
	{
		if (current->value < smallest)
			smallest = current->value;
		current = current->next;
	}
	if (stacks->a->value < smallest)
		return (1);
	return (0);
}

int	is_largest(t_stacks *stacks)
{
	t_stack	*current;
	int	largest;
	
	current = stacks->b;
	largest = current->value;
	while (current != NULL)
	{
		if (current->value > largest)
			largest = current->value;
		current = current->next;
	}
	if (stacks->a->value > largest)
		return (1);
	return (0);
}
