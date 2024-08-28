/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:28:34 by djelacik          #+#    #+#             */
/*   Updated: 2024/08/28 11:39:56 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
	{
		ra(a);
	}
}

static void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (second > third && third > first)
	{
		ra(a);
		sa(a);
	}
	else if (first > second && third > first)
		sa(a);
	else if (second > first && first > third)
		rra(a);
	else if (first > third && third > second)
		ra(a);
}

void	sort_five(t_stacks *stacks)
{
	if (is_sorted(stacks->a))
		return ;
	if (get_stack_size(stacks->a) == 2)
		sort_two(&stacks->a);
	if (get_stack_size(stacks->a) == 3)
		sort_three(&stacks->a);
	if (get_stack_size(stacks->a) == 4)
	{
		smallest_on_top(&stacks->a);
		pb(&stacks->a, &stacks->b);
		sort_three(&stacks->a);
		pa(&stacks->a, &stacks->b);
	}
	if (get_stack_size(stacks->a) == 5)
	{
		smallest_on_top(&stacks->a);
		pb(&stacks->a, &stacks->b);
		smallest_on_top(&stacks->a);
		pb(&stacks->a, &stacks->b);
		sort_three(&stacks->a);
		pa(&stacks->a, &stacks->b);
		pa(&stacks->a, &stacks->b);
	}
}
