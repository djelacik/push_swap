/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 20:23:37 by djelacik          #+#    #+#             */
/*   Updated: 2024/07/14 19:19:49 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **node)
{
	t_stack	*head;
	t_stack	*tail;

	if (!*node || !(*node)->next)
		return ;
	head = *node;
	tail = *node;
	while (tail->next)
	{
		tail = tail->next;
	}
	*node = head->next;
	tail->next = head;
	head->next = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
	write(STDOUT_FILENO, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate(b);
	write(STDOUT_FILENO, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(STDOUT_FILENO, "rr\n", 3);
}
