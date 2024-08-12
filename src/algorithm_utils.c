/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:53:45 by djelacik          #+#    #+#             */
/*   Updated: 2024/08/06 17:29:15 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	correct_position_values(t_stack *stack, int value)
{
	if (get_stack_size(stack) == 1)
		return (1);
	if (stack->value < value
		&& value < last_value(stack))
		return (1);
	if (if_smallest(stack, value) || if_largest(stack, value))
	{
		if (stack->value > last_value(stack))
			return (1);
	}
	return (0);
}

int	get_moves(t_stack *stack, int value)
{
	t_stack	*current;
	int		moves;

	current = stack;
	moves = 0;
	while (current->next)
	{
		if (correct_position_values(current, value))
			return (moves);
		current = current->next;
		moves++;
	}
	return (moves);
}

int	dist_to_top(t_stack *stack, int value)
{
	t_stack	*current;
	int		length;
	int		index;

	length = 0;
	current = stack;
	while (current)
	{
		if (current->value == value)
			index = length;
		length++;
		current = current->next;
	}
	if (index > (length / 2))
		return (1);
	return (0);
}

int	get_direction(t_stack *stack, int to_find)
{
	int		index;
	int		length;
	t_stack	*current;

	index = 0;
	length = 0;
	current = stack;
	while (current != NULL)
	{
		if (correct_position_values(current, to_find))
		{
			index = length;
			break ;
		}
		current = current->next;
		length++;
	}
	if (index > (get_stack_size(stack) / 2))
		return (1);
	return (0);
}

int	get_smallest(t_stack *stack)
{
	t_stack	*current;
	int		min;

	current = stack;
	min = current->value;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
		}
		current = current->next;
	}
	return (min);
}
