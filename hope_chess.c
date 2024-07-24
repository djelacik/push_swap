/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hope_chess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 22:14:04 by djelacik          #+#    #+#             */
/*   Updated: 2024/07/24 12:35:29 by djelacik         ###   ########.fr       */
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
    info->max_value = 0;
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
	//max_index is closer to the end, so RBB
	if (max_index > (length / 2))
		return (1);
	//max_index is closest to the top, so RB
	return (0);
}

static int	return_largest(t_stack *stack)
{
	t_stack	*current;
	int	largest;
	
	current = stack;
	largest = current->value;
	while (current != NULL)
	{
		if (current->value > largest)
			largest = current->value;
		current = current->next;
	}
	return (largest);
}

static void	largest(t_stack **stack, t_info *info)
{
	int	largest;

	largest = return_largest(*stack);
	if (!find_max_index(*stack, info))
	{
		while ((*stack)->value != largest)
		{
			rb(stack);
			largest = return_largest(*stack);
		}
	}
	else
	{
		while ((*stack)->value != largest)
		{
			rrb(stack);
			largest = return_largest(*stack);
		}
	}
}

void	test_algo(t_stacks *stacks, t_info *info)
{
	while (stacks->a)
	{
		pb(&stacks->a, &stacks->b);
	}
	while (stacks->b)
	{
		largest(&stacks->b, info);
		pa(&stacks->a, &stacks->b);
		find_max_index(stacks->b, info);
	}
    //print_stacks(stacks);
}
