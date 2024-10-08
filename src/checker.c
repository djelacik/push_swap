/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:25:02 by djelacik          #+#    #+#             */
/*   Updated: 2024/08/28 11:31:01 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checker(t_stacks *stacks, t_info *info)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		exec_cmds(stacks, info, line, ft_strlen(line) - 1);
		if (info->err_flag)
		{
			free(line);
			free_exit(stacks, EXIT_FAILURE, info);
		}
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
			free_exit(&stacks, EXIT_SUCCESS, info);
		}
		else if (checker(&stacks, info))
			write(STDOUT_FILENO, "OK\n", 3);
		else
		{
			write(STDOUT_FILENO, "KO\n", 3);
			free_stack(&stacks.a);
			free_stack(&stacks.b);
		}
		free_exit(&stacks, EXIT_SUCCESS, info);
	}
	return (0);
}
