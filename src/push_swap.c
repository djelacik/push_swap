/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:19:31 by djelacik          #+#    #+#             */
/*   Updated: 2024/08/28 11:04:18 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	t_info		*info;

	info = NULL;
	if (argc < 2)
		return (EXIT_FAILURE);
	initialize_info(&info, argc, argv);
	if (argc == 2)
		initialize_stacks(&stacks, info, info->argv);
	else
		initialize_stacks(&stacks, info, info->argv);
	if (get_stack_size(stacks.a) <= 5)
		sort_five(&stacks);
	if (is_sorted(stacks.a))
		free_exit(&stacks, EXIT_SUCCESS, info);
	super_algo(&stacks, info);
	free_exit(&stacks, EXIT_SUCCESS, info);
	return (0);
}
