/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 19:35:54 by djelacik          #+#    #+#             */
/*   Updated: 2024/07/26 13:28:28 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_array(t_stack **stack, int size)
{
	t_stack	*current;
	int		*array;
	int		i;

	array = malloc(sizeof(int) * size);
	if (!array)
	{
		error_exit(stack);
	}
	current = *stack;
	i = 0;
	while (current && i < size)
	{
		array[i] = current->value;
		current = current->next;
		i++;
	}
	return (array);
}

static void	calculate_median(t_info *info, int *arr, int size)
{
	int	median;
	int	mid_1;
	int	mid_2;
	
	info->pivot = 0;
	insertion_sort(arr, size);
	if (size % 2 == 1)
	{
		median = arr[size / 2];
		info->pivot = median;
	}
	else
	{
		mid_1 = size / 2 - 1;
		mid_2 = size / 2;
		median = (arr[mid_1] + arr[mid_2]) / 2;
		info->pivot = median;
	}
	free(arr);
}

int	get_pivot(t_stacks *stacks, t_info *info)
{
	calculate_median(info, stack_to_array(&stacks->a, info->size), get_stack_size(stacks->a));
	return (info->pivot);
}
