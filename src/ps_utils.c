/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:04:19 by djelacik          #+#    #+#             */
/*   Updated: 2024/09/06 13:30:45 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_node(t_stack **head, t_info *info, long value)
{
	t_stack	*new_node;
	t_stack	*current;

	if (value == 2147483649)
		return (-1);
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
	{
		free_stack(head);
		return (0);
	}
	new_node->value = value;
	new_node->next = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
	info->size++;
	return (0);
}

int	get_stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int	last_value(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	if (!stack)
		return (0);
	while (current->next != NULL)
		current = current->next;
	return (current->value);
}
