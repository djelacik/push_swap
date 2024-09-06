/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:16:33 by djelacik          #+#    #+#             */
/*   Updated: 2024/09/04 14:15:17 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct s_stack
{
	int				value;
	int				cost;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}	t_stacks;

typedef struct s_tmp_stacks
{
	t_stack	*a;
	t_stack	*b;
}	t_tmp_stacks;

typedef struct s_info
{
	char	**argv;
	int		argc;
	int		size;
	int		counter;
	int		alt_argv;

	int		dup_moves;
	int		src_direct;
	int		dest_direct;

	int		err_flag;
}	t_info;

void	swap(t_stack **node);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	push(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	rotate(t_stack **node);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	reverse_rotate(t_stack **node);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

void	hidden_sa(t_stack **a);
void	hidden_sb(t_stack **b);
void	hidden_ss(t_stack **a, t_stack **b);
void	hidden_pa(t_stack **a, t_stack **b);
void	hidden_pb(t_stack **a, t_stack **b);
void	hidden_ra(t_stack **a);
void	hidden_rb(t_stack **b);
void	hidden_rr(t_stack **a, t_stack **b);
void	hidden_rra(t_stack **a);
void	hidden_rrb(t_stack **b);
void	hidden_rrr(t_stack **a, t_stack **b);

int		add_node(t_stack **head, t_info *info, long value);
int		get_stack_size(t_stack *stack);
int		validator(t_stack **stack);
void	free_stack(t_stack **stack);
void	free_array(char **array);
int		is_sorted(t_stack *stack);
void	free_exit(t_stacks *stacks, int exit_code, t_info *info);
void	initialize_info(t_info **info_ptr, int argc, char **argv);
void	initialize_stacks(t_stacks *stacks, t_info *info, char **vc);

int		last_value(t_stack *stack);
int		if_smallest(t_stack *stack, int value);
int		if_largest(t_stack *stack, int value);
int		correct_position_values(t_stack *stack, int value);
int		get_moves(t_stack *stack, int value);
int		dist_to_top(t_stack *stack, int value);
int		get_direction(t_stack *stack, int to_find);
int		get_smallest(t_stack *stack);

int		cost_to_top(t_stack *stack, int value);
int		calculate_moves(t_stack *src, t_stack *dest, int value);
int		find_cheapest(t_stack *src);
void	set_cost(t_stack *src, t_stack *dest, t_info *info);
void	save_cheapest(t_stack *src, t_stack *dest, t_info *info, int value);
void	exec_commands(t_stack **src, t_stack **dest, t_info *info);
void	smallest_on_top(t_stack **stack);
void	dup_rotates(t_stack **src, t_stack **dest, t_info *info);
void	sort_five(t_stacks *stacks);

void	exec_cmds(t_stacks *stacks, t_info *info, char *cmd, int len);
int		checker(t_stacks *stacks, t_info *info);

void	super_algo(t_stacks *stacks, t_info *info);

#endif
