/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:19:31 by djelacik          #+#    #+#             */
/*   Updated: 2024/08/08 16:33:47 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			exit (EXIT_SUCCESS);
		super_algo(stacks.a, stacks.b, info);
		free_stack(&stacks.a);
		free_stack(&stacks.b);
		free(info);
	}
	return (0);
}
