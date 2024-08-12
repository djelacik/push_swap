/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:25:02 by djelacik          #+#    #+#             */
/*   Updated: 2024/08/12 10:58:07 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error_free(t_stacks **stacks)
{
	write(STDERR_FILENO, "Error\n", 6);
	free_stack(&(*stacks)->a);
	free_stack(&(*stacks)->b);
	exit (1);
}

int	checker(t_stacks *stacks, t_info *info)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		exec_cmds(stacks, info, line, ft_strlen(line) - 1);
		if (info->err_flag)
			error_free(&stacks);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	if (is_sorted(stacks->a) && stacks->b == NULL)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	t_info		*info;

	info = NULL;
	if (argc != 2)
	{
		initialize_info(&info, argc, argv);
		initialize_stacks(&stacks, info, argv);
		if (is_sorted(stacks.a))
		{
			write(STDOUT_FILENO, "OK\n", 3);
			exit (EXIT_SUCCESS);
		}
		if (checker(&stacks, info))
			write(STDOUT_FILENO, "OK\n", 3);
		else
			write(STDOUT_FILENO, "KO\n", 3);
		free_stack(&stacks.a);
		free_stack(&stacks.b);
		free(info);
	}
	return (0);
}
