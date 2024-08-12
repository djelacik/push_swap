/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidden_swap_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 14:06:49 by djelacik          #+#    #+#             */
/*   Updated: 2024/08/10 14:18:12 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hidden_sa(t_stack **a)
{
	swap(a);
}

void	hidden_sb(t_stack **b)
{
	swap(b);
}

void	hidden_ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}

void	hidden_pa(t_stack **a, t_stack **b)
{
	push(a, b);
}

void	hidden_pb(t_stack **a, t_stack **b)
{
	push(b, a);
}
