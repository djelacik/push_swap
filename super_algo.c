/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:36:16 by djelacik          #+#    #+#             */
/*   Updated: 2024/07/30 13:09:11 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	if_smallest(t_stack *stack, int value)
{
	t_stack	*current;
	
	current = stack;
	while (current)
	{
		if (current->value < value)
			return (0);
		current = current->next;
	}
	return (1);
}
static int	if_largest(t_stack *stack, int value)
{
	t_stack	*current;
	
	current = stack;
	while (current)
	{
		if (current->value > value)
			return (0);
		current = current->next;
	}
	return (1);
}

static int	correct_position_values(t_stack *stack, int value)
{
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


static int	get_moves(t_stack *stack, int value)
{
	t_stack *current;
	int		moves;
	
	current = stack;
	moves = 0;
	while (current->next)
	{
		if (correct_position_values(stack, value))
			return (moves);
		current = current->next;
		moves++;
	}
	return (moves);
}

static int	cost_to_top(t_stack *stack, int value)
{
	t_stack	*current;
	int		index;

	current = stack;
	index = 0;
	while (stack->value != value)
	{
		index++;
		current = current->next;
	}
	if (index > (get_stack_size(stack) / 2))
		index = get_stack_size(stack) - index;
	return (index);
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
		if (correct_position_values(stack, to_find)
				|| to_find == current->value)
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
	if (src_direct == dest_direct && 1 == 2)
	{
		total -= ft_min(src_moves, dest_moves);
	}
	return (total);
}

static void	set_cost(t_stack *src, t_stack *dest)
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
}

static int	find_cheapest(t_stack *src)
{
	t_stack	*current;
	int 	min;
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
	//return (current->rank);
}

static void	exec_commands(t_stack *src, t_stack *dest)
{
	while (src->value != find_cheapest(src))
	{
		if (get_direction(src, src->value))
		{
			rra(&src);
		}
		else
		{
			ra(&src);
		}
	}
	
	while (!correct_position_values(dest, src->value))
	{
		if (get_direction(dest, src->value))
		{
			rrb(&dest);
		}
		else
		{
			rb(&dest);
		}
	}
	pb(&src, &dest);
}

void hope_algo(t_stack *src, t_stack *dest)
{
	pb(&src, &dest);
	pb(&src, &dest);
	set_cost(src, dest);
	while (src)
	{
		exec_commands(src, dest);
	}
}
