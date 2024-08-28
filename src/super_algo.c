/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:36:16 by djelacik          #+#    #+#             */
/*   Updated: 2024/08/28 11:29:27 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smallest_on_top(t_stack **stack)
{
	int		smallest;

	smallest = get_smallest(*stack);
	while ((*stack)->value != smallest)
	{
		if (dist_to_top(*stack, smallest))
			rra(stack);
		else
			ra(stack);
	}
}

void	dup_rotates(t_stack **src, t_stack **dest, t_info *info)
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

void	exec_commands(t_stack **src, t_stack **dest, t_info *info)
{
	set_cost(*src, *dest, info);
	dup_rotates(src, dest, info);
	while ((*src)->value != find_cheapest((*src)))
	{
		if (dist_to_top(*src, find_cheapest((*src))))
			rra(src);
		else
			ra(src);
	}
	while (!correct_position_values(*dest, (*src)->value))
	{
		if (get_direction(*dest, (*src)->value))
			rrb(dest);
		else
			rb(dest);
	}
	pb(src, dest);
}

void	super_algo(t_stacks *stacks, t_info *info)
{
	pb(&stacks->a, &stacks->b);
	pb(&stacks->a, &stacks->b);
	while (stacks->a)
	{
		exec_commands(&stacks->a, &stacks->b, info);
	}
	rb(&stacks->b);
	while (stacks->b)
	{
		pa(&stacks->a, &stacks->b);
	}
	smallest_on_top(&stacks->a);
}
