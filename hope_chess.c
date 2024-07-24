/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hope_chess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 22:14:04 by djelacik          #+#    #+#             */
/*   Updated: 2024/07/24 22:50:10 by djelacik         ###   ########.fr       */
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

static int	return_largest(t_stack *stack, t_info *info)
{
	t_stack	*current;
	int		largest;
	int		i;
	
	current = stack;
	largest = 0;
	i = 0;
	while ((i + info->counter) < get_stack_size(stack)
            && current != NULL)
	{
		if (current->value > largest)
			largest = current->value;
		current = current->next;
		i++;
	}
	return (largest);
}

static void	find_two_largest(t_stack *stack, t_info *info)
{
	t_stack	*current;

	info->counter = 0;
	info->max_value = return_largest(stack, info);
	info->second_max = 0;
	current = stack;
	
	while (current)
	{
		if (current->value > info->second_max
				&& current->value != info->max_value)
			info->second_max = current->value;
		current = current->next;
	}
}

static void	largest(t_stack **stack, t_info *info)
{
	int	largest;

	largest = return_largest(*stack, info);
	if (!find_max_index(*stack, info))
	{
		while ((*stack)->value != largest)
		{
			rb(stack);
			largest = return_largest(*stack, info);
		}
	}
	else
	{
		while ((*stack)->value != largest)
		{
			rrb(stack);
			largest = return_largest(*stack, info);
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

static void	correct_rotate(t_stack **stack, t_info *info)
{
	if (!find_max_index(*stack, info))
	{
		if ((*stack)->value != info->max_value)
			rb(stack);
	}
	else
	{
		if ((*stack)->value != info->max_value)
			rrb(stack);
	}
}

void	new_algo(t_stacks *stacks, t_info *info)
{
	int	flag;

	flag = 0;
	//find_two_largest(stacks->a, info);
	while (stacks->a->next)
	{
		if (stacks->a->value == return_largest(stacks->a, info))
		{
			ra(&stacks->a);
			info->counter++;
		}
		else
		{
			pb(&stacks->a, &stacks->b);
		}
	}
	while (info->counter > 1)
	{
		pa(&stacks->a, &stacks->b);
		ra(&stacks->a);
		info->counter--;
	}
	find_two_largest(stacks->b, info);
	while (stacks->b)
	{
		info->counter = 0;
		if (stacks->b->value == info->second_max)
		{
			pa(&stacks->a, &stacks->b);
			flag = 1;
		}
		else if (stacks->b->value == info->max_value)
		{
			pa(&stacks->a, &stacks->b);
			if (flag == 1)
			{
				swap(&stacks->a);
			}
			flag = 0;
			find_two_largest(stacks->b, info);
		}
		else
		{
			correct_rotate(&stacks->b, info);
		}
	}
	//print_stacks(stacks);
}

