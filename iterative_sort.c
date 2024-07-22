/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterative_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:21:54 by djelacik          #+#    #+#             */
/*   Updated: 2024/07/22 20:57:20 by djelacik         ###   ########.fr       */
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
				stacks->b->value < stacks->a->value && 
				stacks->a->value < last_value(stacks->b))
			{
				pb(&stacks->a, &stacks->b);
			}
			else if (stacks->b != NULL && stacks->b->next != NULL &&
				stacks->b->value > stacks->a->value)
			{
				if (compare_all(stacks))
				{
					largest_on_top(&stacks->b, info);
					pb(&stacks->a, &stacks->b);
					rb(&stacks->b);
				}
				// if stacks->a < all stacks->b->values 
				// return 1
				// b largest on top
				// pb
				// rb after it to get smallest last

				while (stacks->b != NULL && stacks->b->next != NULL &&
				stacks->b->value > stacks->a->value)
				{
					rb(&stacks->b);
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
	print_stacks(stacks);
	while (stacks->b->value > stacks->a->value)
	{
		rrb(&stacks->b);
	}
	while (stacks->b)
	{
		pa(&stacks->a, &stacks->b);
	}
    print_stacks(stacks);
}
