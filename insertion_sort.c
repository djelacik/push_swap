/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:12:15 by djelacik          #+#    #+#             */
/*   Updated: 2024/07/13 20:19:51 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insert_sorted_pos(int *arr, int i)
{
	int	key;
	int	j;

	key = arr[i];
	j = i - 1;
	while (j >= 0 && arr[j] > key)
	{
		arr[j + 1] = arr[j];
		j--;
	}
	arr[j + 1] = key;
}

void	insertion_sort(int *arr, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		insert_sorted_pos(arr, i);
		i++;
	}
}
