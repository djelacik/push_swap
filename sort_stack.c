/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:36:21 by djelacik          #+#    #+#             */
/*   Updated: 2024/07/17 13:27:16 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	recursive_sort(t_stacks *stacks, t_info *info, int size)
{
	int	pivot;
	int processed_b;
	int	i;

	if (size <= 1)
		return ;
	pivot = get_pivot(stacks->a, info);
	dbg_printf("Pivot is :%d", pivot);
	processed_b = 0;
	i = 1;
	while (i < size - 1)
	{
		if (stacks->a->value < pivot)
		{
			pb(&stacks->a, &stacks->b);
			processed_b++;
		}
		else
		{
			ra(&stacks->a);
		}
		i++;
	}
	recursive_sort(stacks, info, size - processed_b);
	while (processed_b--)
	{
		pa(&stacks->b, &stacks->a);
	}
	recursive_sort(stacks, info, processed_b);
}

void	sort_stack(t_stacks *stacks, t_info *info)
{
	int	total_size_a;

	total_size_a = get_stack_size(stacks->a);
	recursive_sort(stacks, info, total_size_a);
}