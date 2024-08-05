/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:36:16 by djelacik          #+#    #+#             */
/*   Updated: 2024/08/05 16:37:27 by djelacik         ###   ########.fr       */
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
		//if value smaller than any stack value, value is not the bigest
		if (current->value > value)
			return (0);
		current = current->next;
	}
	return (1);
}

static int	correct_position_values(t_stack *stack, int value)
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


static int	get_moves(t_stack *stack, int value)
{
	t_stack *current;
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

static int	cost_to_top(t_stack *stack, int value)
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
	// if (index > (get_stack_size(stack) / 2))
	// 	index = get_stack_size(stack) - index;
	return (index);
}

static int	dist_to_top(t_stack *stack, int value)
{
	t_stack	*current;
	int		length;
	int		index;

	//index = 0;
	length = 0;
    current = stack;
	while (current)
	{
		if (current->value == value)
			index = length;
		length++;
		current = current->next;
	}
	//index is closer to the end, so RRA
	if (index > (length / 2))
		return (1);
	//index is closest to the top, so RA
	return (0);
}
static int	get_smallest(t_stack *stack)
{
	t_stack	*current;
	int 	min;
	
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

static void	smallest_on_top(t_stack **stack)
{
	int		smallest;

	smallest = get_smallest(*stack);
	while ((*stack)->value != smallest)
	{
		if (dist_to_top(*stack, smallest))
		{
			rra(stack);
		}
		else
		{
			ra(stack);
		}
	}
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
	//index is closer to the end, so RRB
	if (index > (get_stack_size(stack) / 2))
		return (1);
	//index is closest to the top, so RB
	return (0);
}
static void	save_cheapest(t_stack *src, t_stack *dest, t_info *info, int value)
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
	if (src_direct == dest_direct)
	{
		total -= ft_min(src_moves, dest_moves);
	}
	return (total);
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

static void	dup_rotates(t_stack **src, t_stack **dest, t_info *info)
{
	if (info->src_direct == 1 && info->dest_direct == 1)
	{
		while (info->dup_moves)
		{
			rrr(src, dest);
			info->dup_moves--;
		}
	}
	if (info->src_direct == 2 && info->dest_direct == 2)
	{
		while (info->dup_moves)
		{
			rr(src, dest);
			info->dup_moves--;
		}
	}
}


static void	exec_commands(t_stack **src, t_stack **dest, t_info *info)
{
	set_cost(*src, *dest, info);
	dup_rotates(src, dest, info);
	while ((*src)->value != find_cheapest((*src)))
	{
		if (dist_to_top(*src, find_cheapest((*src))))
		{
			rra(src);
		}
		else
		{
			ra(src);
		}
	}
	
	while (!correct_position_values(*dest, (*src)->value))
	{
		if (get_direction(*dest, (*src)->value))
		{
			rrb(dest);
		}
		else
		{
			rb(dest);
		}
	}
	pb(src, dest);
}

void	hope_algo(t_stack *src, t_stack *dest, t_info *info)
{
	pb(&src, &dest);
	pb(&src, &dest);
	while (src)
	{
		exec_commands(&src, &dest, info);
	}
	rb(&dest);
	while (dest)
	{
		pa(&src, &dest);
	}
	smallest_on_top(&src);
	print_stack('A', src);
}
