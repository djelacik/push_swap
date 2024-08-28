/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:40:36 by djelacik          #+#    #+#             */
/*   Updated: 2024/08/28 11:34:45 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_exit(t_stacks *stacks, int exit_code, t_info *info)
{
	if (exit_code)
		write(STDERR_FILENO, "Error\n", 6);
	(void)stacks;
	if (stacks->a)
		free_stack(&(stacks->a));
	if (stacks->b)
		free_stack(&(stacks->b));
	if (info->alt_argv)
	{
		free_array(info->argv);
	}
	if (info)
		free(info);
	exit (exit_code);
}

void	free_array(char **array)
{
	int	i;

	i = -1;
	if (!array)
		return ;
	while (array[++i])
		free(array[i]);
	free(array);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	*stack = NULL;
}
