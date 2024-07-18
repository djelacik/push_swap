/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterative_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:21:54 by djelacik          #+#    #+#             */
/*   Updated: 2024/07/18 13:52:25 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	iterative_sort(t_stacks *stacks, t_info *info)
{	
	while (get_stack_size(stacks->a) > 1)
	{
		print_stacks(stacks);
		dbg_printf("Stack size A: %d    B: %d\n", get_stack_size(stacks->a), get_stack_size(stacks->b));
		info->pivot = get_pivot(stacks, info);
		dbg_printf("Pivot is : %d\n", info->pivot);
		if (stacks->a->value <= info->pivot)
		{
			if (stacks->b != NULL && stacks->b->next != NULL &&
				stacks->b->value < stacks->a->value)
			{
				pb(&stacks->a, &stacks->b);
			}
			else if (stacks->b != NULL && stacks->b->next != NULL &&
				stacks->b->value > stacks->a->value)
			{
				while (stacks->b != NULL && stacks->b->next != NULL &&
				stacks->b->value > stacks->b->next->value)
				{
					rb(&stacks->b);
					//rrb(&stacks->b);
				}
				pb(&stacks->a, &stacks->b);
			}
			else
			{
				pb(&stacks->a, &stacks->b);
			}
		}
		else
		{
			ra(&stacks->a);
		}
	}
	// if (stacks->a->value > stacks->a->next->value)
	// {
	// 	ra(&stacks->a);
	// }
	print_stacks(stacks);
	while (stacks->b->value > stacks->a->value)
	{
		rrb(&stacks->b);
	}
	while (stacks->b)
	{
		pa(&stacks->b, &stacks->b);
	}
}
