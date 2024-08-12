/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_costs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:05:57 by djelacik          #+#    #+#             */
/*   Updated: 2024/08/06 17:34:17 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_to_top(t_stack *stack, int value)
{
	t_stack	*current;
	int		index;

	current = stack;
	index = 0;
	while (current->value != value)
	{
		index++;
		current = current->next;
	}
	return (index);
}

int	calculate_moves(t_stack *src, t_stack *dest, int value)
{
	int	src_moves;
	int	dest_moves;
	int	total;
	int	src_direct;
	int	dest_direct;

	src_moves = cost_to_top(src, value);
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
		total -= ft_min(src_moves, dest_moves);
	return (total);
}

int	find_cheapest(t_stack *src)
{
	t_stack	*current;
	int		min;
	int		value;

	current = src;
	min = current->cost;
	value = current->value;
	while (current)
	{
		if (current->cost < min)
		{
			min = current->cost;
			value = current->value;
		}
		current = current->next;
	}
	return (value);
}

void	set_cost(t_stack *src, t_stack *dest, t_info *info)
{
	t_stack	*current;

	current = src;
	while (current)
	{
		current->cost = calculate_moves(src, dest, current->value);
		current = current->next;
	}
	current = dest;
	while (current)
	{
		current->cost = calculate_moves(dest, src, current->value);
		current = current->next;
	}
	current = src;
	while (current)
	{
		if (current->value == find_cheapest(current))
		{
			save_cheapest(src, dest, info, current->value);
			break ;
		}
		current = current->next;
	}
}

void	save_cheapest(t_stack *src, t_stack *dest, t_info *info, int value)
{
	int	src_moves;
	int	dest_moves;

	src_moves = cost_to_top(src, value);
	dest_moves = get_moves(dest, value);
	if (src_moves > (get_stack_size(src) / 2))
	{
		src_moves = get_stack_size(src) - src_moves;
		info->src_direct = 1;
	}
	else
		info->src_direct = 2;
	if (dest_moves > (get_stack_size(dest) / 2))
	{
		dest_moves = get_stack_size(dest) - dest_moves;
		info->dest_direct = 1;
	}
	else
		info->dest_direct = 2;
	if (info->src_direct == info->dest_direct)
		info->dup_moves = ft_min(src_moves, dest_moves);
}
