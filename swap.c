/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:36:05 by djelacik          #+#    #+#             */
/*   Updated: 2024/08/06 17:33:11 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **node)
{
	int	temp;

	if (*node && (*node)->next != NULL)
	{
		temp = (*node)->value;
		(*node)->value = (*node)->next->value;
		(*node)->next->value = temp;
	}
}

void	sa(t_stack **a)
{
	swap(a);
	write(STDOUT_FILENO, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap(b);
	write(STDOUT_FILENO, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(STDOUT_FILENO, "ss\n", 3);
}
