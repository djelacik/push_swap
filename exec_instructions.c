/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:36:49 by djelacik          #+#    #+#             */
/*   Updated: 2024/08/10 14:59:55 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_cmds(t_stacks *stacks, t_info *info, char *cmd, int len)
{
	if (!ft_strncmp(cmd, "sa", len))
		hidden_sa(&stacks->a);
	else if (!ft_strncmp(cmd, "sb", len))
		hidden_sb(&stacks->b);
	else if (!ft_strncmp(cmd, "ss", len))
		hidden_ss(&stacks->a, &stacks->b);
	else if (!ft_strncmp(cmd, "pa", len))
		hidden_pa(&stacks->a, &stacks->b);
	else if (!ft_strncmp(cmd, "pb", len))
		hidden_pb(&stacks->b, &stacks->a);
	else if (!ft_strncmp(cmd, "ra", len))
		hidden_ra(&stacks->a);
	else if (!ft_strncmp(cmd, "rb", len))
		hidden_rb(&stacks->b);
	else if (!ft_strncmp(cmd, "rr", len))
		hidden_rr(&stacks->a, &stacks->b);
	else if (!ft_strncmp(cmd, "rra", len))
		hidden_rra(&stacks->a);
	else if (!ft_strncmp(cmd, "rrb", len))
		hidden_rrb(&stacks->b);
	else if (!ft_strncmp(cmd, "rrr", len))
		hidden_rrr(&stacks->a, &stacks->b);
	else
		info->err_flag = 1;
}
