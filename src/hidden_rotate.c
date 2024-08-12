/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidden_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 14:19:52 by djelacik          #+#    #+#             */
/*   Updated: 2024/08/10 14:20:50 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hidden_ra(t_stack **a)
{
	rotate(a);
}

void	hidden_rb(t_stack **b)
{
	rotate(b);
}

void	hidden_rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
