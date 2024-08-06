/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:39:34 by djelacik          #+#    #+#             */
/*   Updated: 2024/08/06 17:20:13 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **dest, t_stack **src)
{
	t_stack	*temp;

	if (*src)
	{
		temp = *src;
		*src = (*src)->next;
		temp->next = *dest;
		*dest = temp;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	write(STDOUT_FILENO, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	push(b, a);
	write(STDOUT_FILENO, "pb\n", 3);
}
