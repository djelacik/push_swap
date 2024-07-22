/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   largest_on_top.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:21:46 by djelacik          #+#    #+#             */
/*   Updated: 2024/07/22 20:55:31 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_index(t_stack *stack, t_info *info)
{
	int		max_index;
	int		length;
	t_stack	*current;

	max_index = 0;
	length = 0;
	current = stack;
	while (current != NULL)
	{
		if (current->value > info->max_value)
		{
			info->max_value = current->value;
			max_index = length;
		}
		current = current->next;
		length++;
	}
	//max_index is closest to the end, so RB
	if (max_index > (length / 2))
		return (1);
	//max_index is closest to the top, so RRB
	return (0);
}

void	largest_on_top(t_stack **stack, t_info *info)
{
	if (find_max_index)
	{
		while ((*stack)->value != info->max_value)
			rb(stack);
	}
	else
	{
		while ((*stack)->value != info->max_value)
			rrb(stack);
	}
}
