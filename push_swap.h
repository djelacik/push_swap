/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:16:33 by djelacik          #+#    #+#             */
/*   Updated: 2024/08/05 16:42:36 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

#include <stdio.h>

//#define DBG_PRINT_FD

#ifdef DBG_PRINT_FD
#define dbg_printf(...) fprintf(stderr, __VA_ARGS__)
#else
#define dbg_printf(...)
#endif

typedef struct s_stack
{
	int				value;
	int				cost;
//	int				rank;
	struct s_stack	*next;
} t_stack;

typedef struct s_stacks
{
	t_stack *a;
	t_stack *b;
} t_stacks;

typedef	struct s_info
{
	char	**argv;
	int		argc;
	int		size;
	int		pivot;
	int		last_value;
	int		max_value;
	int		second_max;
	int		counter;

	int		dup_moves;
	int		src_direct;
	int		dest_direct;
} t_info;

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

void	add_node(t_stack **head, t_info *info, int value);
void	print_stacks(t_stacks *stacks);
int		get_stack_size(t_stack *stack);
void	free_stack(t_stack **stack);
int		validator(t_stack **stack);
void	error_exit(t_stack **stack);
void	initialize_info(t_info **info_ptr, int argc, char **argv);
void	initialize_stacks(t_stacks *stacks, t_info *info, char **vc);

int		get_pivot(t_stacks *stacks, t_info *info);

void	insertion_sort(int *arr, int size);
void	sort_stack(t_stacks *stacks, t_info *info);
void	recursive_sort(t_stacks *stacks, t_info *info, int size);
void	iterative_sort(t_stacks *stacks, t_info *info);
int		last_value(t_stack *stack);
int		is_smallest(t_stacks *stacks);
int		is_largest(t_stacks *stacks);
void	largest_on_top(t_stack **stack, t_info *info);
int		find_index(t_stack *stack, int to_find);
int		is_correct_pos(t_stacks *stacks);
void	rotate_and_insert(t_stacks *stacks);

void	test_algo(t_stacks *stacks, t_info *info);
void	new_algo(t_stacks *stacks, t_info *info);

int		*stack_to_array(t_stack **stack, int size);
int		get_direction(t_stack *stack, int to_find);

void	hope_algo(t_stack *src, t_stack *dest, t_info *info);

void	print_stack(char name, t_stack *stack);

#endif
