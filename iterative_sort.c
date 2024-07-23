/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterative_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:21:54 by djelacik          #+#    #+#             */
/*   Updated: 2024/07/23 21:19:31 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	iterative_sort(t_stacks *stacks, t_info *info)
{	
	while (get_stack_size(stacks->a) > 1)
	{
		//print_stacks(stacks);
		//dbg_printf("Stack size A: %d    B: %d\n", get_stack_size(stacks->a), get_stack_size(stacks->b));
		info->pivot = get_pivot(stacks, info);
		//dbg_printf("Pivot is : %d\n", info->pivot);
		if (stacks->a->value <= info->pivot)
		{
			if (stacks->b != NULL && stacks->b->next != NULL)
			{
				if (is_smallest(stacks))
				{
					largest_on_top(&stacks->b, info);
					pb(&stacks->a, &stacks->b);
					rb(&stacks->b);
				}
				if (is_largest(stacks))
				{
					largest_on_top(&stacks->b, info);
					pb(&stacks->a, &stacks->b);
				}
				else
				{
					rotate_and_insert(stacks);
				}
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
	largest_on_top(&stacks->b, info);
	while (stacks->b)
	{
		pa(&stacks->a, &stacks->b);
	}
    print_stacks(stacks);
}
