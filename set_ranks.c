/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ranks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:57:21 by djelacik          #+#    #+#             */
/*   Updated: 2024/07/26 13:33:00 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_ranks(t_stack *head, int *array, int count)
{
	t_stack	*current;
	int		i;

	current = head;
	while (current)
	{
		i = 0;
		while (i <= count)
		{
			if (array[i] = current->value)
			{
				current->rank = i;
				break;
			}
			i++;
		}
		current = current->next;
	}
}

void	calculate_ranks(t_stack **stack)
{
	int	size;
	int	*values;

	size = get_stack_size(*stack);
	values = stack_to_array(stack, size);
	insertion_sort(values, size);
	set_ranks(*stack, values, size);
	free(values);
}