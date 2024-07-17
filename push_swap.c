/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:19:31 by djelacik          #+#    #+#             */
/*   Updated: 2024/07/16 15:03:50 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_info(t_info **info_ptr, int argc, char **argv)
{
	*info_ptr = malloc(sizeof(t_info));
	if (!*info_ptr)
		exit(EXIT_FAILURE);
	ft_bzero(*info_ptr, sizeof(t_info));
	(*info_ptr)->argc = argc;
	(*info_ptr)->argv = argv;
}

void	initialize_stacks(t_stacks *stacks, t_info *info, char **vc)
{
	int	i;

	stacks->a = NULL;
	stacks->b = NULL;
	i = 1;
	while (info->argv[i])
	{
		if (!str_is_digit(vc[i]))
			error_exit(&stacks->a);
		add_node(&stacks->a, info, ft_atoi(vc[i]));
		i++;
	}
	if (validator(&stacks->a))
		error_exit(&stacks->a);
	get_pivot(&stacks->a, info);
}

int	main(int argc, char **argv)
{
	t_stacks 	stacks;
	t_info		*info;
	
	info = NULL;

	if (argc != 2)
	{
		initialize_info(&info, argc, argv);
		initialize_stacks(&stacks, info, argv);
		iterative_sort(&stacks, info);
		//sort_stack(&stacks, info);
		//print_stacks(&stacks);
		free_stack(&stacks.a);
		free_stack(&stacks.b);
		free(info);
	}
	return (0);
}
