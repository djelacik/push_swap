/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:19:31 by djelacik          #+#    #+#             */
/*   Updated: 2024/08/21 15:23:48 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void print_stack(t_stack *stack)
{
    while (stack != NULL)
    {
        printf("%d\n", stack->value);
        stack = stack->next;
    }
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	t_info		*info;

	info = NULL;
	if (argc == 2)
	{
		initialize_info(&info, argc, argv);
		initialize_stacks(&stacks, info, info->argv);
	}
	else if (argc > 2)
	{
		initialize_info(&info, argc, argv);
		initialize_stacks(&stacks, info, argv);
	}
	else
		return (EXIT_FAILURE);
	if (get_stack_size(stacks.a) <= 5)
		sort_five(&stacks.a, &stacks.b);
	print_stack(stacks.a);
	if (is_sorted(stacks.a))
		free_exit(&stacks, EXIT_SUCCESS);
	super_algo(stacks.a, stacks.b, info);
	free(info);
	free_exit(&stacks, EXIT_SUCCESS);
	return (0);
}
