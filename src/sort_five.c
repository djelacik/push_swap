/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:28:34 by djelacik          #+#    #+#             */
/*   Updated: 2024/08/21 16:12:07 by djelacik         ###   ########.fr       */
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
	if ((*a)->value > (*a)->next->value
			&& (*a)->next->value > (*a)->next->next->value)
	{
		swap(a);
		reverse_rotate(a);
	}
	else if ((*a)->next->value > (*a)->next->next->value
			&& (*a)->next->next->value > (*a)->value)
	{
		reverse_rotate(a);
		swap(a);
	}
	else if ((*a)->value > (*a)->next->next->value
			&& (*a)->next->next->value > (*a)->next->value)
		swap(a);
	else if ((*a)->next->value > (*a)->value
			&& (*a)->value > (*a)->next->next->value)
		rra(a);
}

void	sort_five(t_stack **a, t_stack **b)
{
	if (get_stack_size(*a) == 2)
		sort_two(a);
	if (get_stack_size(*a) == 3)
		sort_three(a);
	if (get_stack_size(*a) == 4)
	{
		smallest_on_top(a);
		pb(a, b);
		sort_three(a);
		pa(a, b);		
	}
	if (get_stack_size(*a) == 5)
	{
		smallest_on_top(a);
		pb(a, b);
		smallest_on_top(a);
		pb(a, b);
		sort_three(a);
		pa(a, b);
		pa(a, b);
	}
}
