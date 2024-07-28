/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:36:16 by djelacik          #+#    #+#             */
/*   Updated: 2024/07/28 20:10:58 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int	correct_position(t_stack *stack, int value)
{
	if (stack->value < stack->next->value
			&& stack->value < last_value(stack))
		return (1);
	else if (stack->value > value
				&& value > stack->next->value)
		return (1);
	return (0);
}

static int	get_moves(t_stack *stack, int value)
{
	t_stack *current;
	int		moves;
	
	current = stack;
	moves = 0;
	while (current->next)
	{
		if (correct_position(stack, value))
			return (moves);
		current = current->next;
		moves++;
	}
	return (moves);
}

int	get_direction(t_stack *stack, int to_find)
{
	int		index;
	int		length;
	t_stack	*current;

	index = 0;
	length = 0;
	current = stack;
	while (current->next != NULL)
	{
		if (current->value < to_find
			&& to_find < last_value(stack))
				break ;
		if (current->value > to_find
				&& current->next->value < to_find)
			index = length;
		current = current->next;
		length++;
	}
	//index is closer to the end, so RRB
	if (index > (length / 2))
		return (1);
	//index is closest to the top, so RB
	return (0);
}

static int	calculate_moves(t_stack *src, t_stack *dest, int value)
{
	int	src_moves;
	int	dest_moves;
	int	total;
	int	src_direct;
	int	dest_direct;

	src_moves = get_moves(src, value);
	dest_moves = get_moves(dest, value);
	src_direct = 0;
	dest_direct = 0;
	if (src_moves > (get_stack_size(src) / 2))
	{
		src_moves = get_stack_size(src) - src_moves;
		src_direct = 1;
	}
	if (dest_moves > (get_stack_size(dest) / 2))
	{
		dest_moves = get_stack_size(dest) - dest_moves;
		dest_direct = 1;
	}
	total = src_moves + dest_moves;
	if (src_direct == dest_direct)
	{
		total -= ft_min(src_moves, dest_moves);
	}
	return (total);	
}

static void	set_cost(t_stack *src, t_stack *dest, t_info *info)
{
	t_stack	*current;

	current = src;
	while (current)
	{
		current->cost = calculate_moves(src, dest, current->value);
		current = current->next;
	}
	current = dest;
	while (dest)
	{
		current->cost = calculate_moves(dest, src, current->value);
		current = current->next;	
	}
}
