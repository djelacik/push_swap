/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:33:14 by djelacik          #+#    #+#             */
/*   Updated: 2024/08/28 11:31:58 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_info(t_info **info_ptr, int argc, char **argv)
{
	*info_ptr = malloc(sizeof(t_info));
	if (!*info_ptr)
	{
		exit(EXIT_FAILURE);
	}
	ft_bzero(*info_ptr, sizeof(t_info));
	(*info_ptr)->argc = argc;
	(*info_ptr)->argv = argv;
	if (argc == 2)
	{
		(*info_ptr)->argv = ft_split(argv[1], ' ');
		(*info_ptr)->alt_argv = 1;
	}
}

void	initialize_stacks(t_stacks *stacks, t_info *info, char **vc)
{
	int	i;

	stacks->a = NULL;
	stacks->b = NULL;
	i = 1;
	if (info->alt_argv)
		i = 0;
	while (info->argv[i])
	{
		if (!str_is_digit(vc[i]))
		{
			free_stack(&stacks->a);
			free_exit(stacks, EXIT_FAILURE, info);
		}
		if (add_node(&stacks->a, info, ft_atoi(vc[i])) == -1)
			free_exit(stacks, EXIT_FAILURE, info);
		i++;
	}
	if (validator(&stacks->a))
		free_exit(stacks, EXIT_FAILURE, info);
}
