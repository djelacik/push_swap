/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterative_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:21:54 by djelacik          #+#    #+#             */
/*   Updated: 2024/07/17 11:14:44 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	iterative_sort(t_stacks *stacks, t_info *info)
{	
	while (get_stack_size(stacks->a) > 2)
	{
		print_stacks(stacks);
		dbg_printf("Stack size A: %d    B: %d\n", get_stack_size(stacks->a), get_stack_size(stacks->b));
		info->pivot = get_pivot(&stacks->a, info);
		dbg_printf("Pivot is : %d\n", info->pivot);
		if (stacks->a->value <= info->pivot)
		{
			while (stacks->b != NULL && stacks->a->value > stacks->b->value 
					&& stacks->b->next != NULL)
			{
				rb(&stacks->b);
				print_stacks(stacks);
			}
			pb(&stacks->a, &stacks->b);
		}
		else
		{
			ra(&stacks->a);
		}
	}
	if (stacks->a->value > stacks->a->next->value)
	{
		ra(&stacks->a);
	}
	while (stacks->b->value > stacks->a->value)
	{
		rrb(&stacks->b);
	}
	while (stacks->b)
	{
		pa(&stacks->b, &stacks->b);
	}
}
