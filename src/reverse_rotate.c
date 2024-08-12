/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:50:02 by djelacik          #+#    #+#             */
/*   Updated: 2024/08/06 17:31:34 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **node)
{
	t_stack	*second_last;
	t_stack	*tail;

	if (!*node || !(*node)->next)
		return ;
	tail = *node;
	second_last = NULL;
	while (tail->next)
	{
		second_last = tail;
		tail = tail->next;
	}
	second_last->next = NULL;
	tail->next = *node;
	*node = tail;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	write(STDOUT_FILENO, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	write(STDOUT_FILENO, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(STDOUT_FILENO, "rrr\n", 4);
}
