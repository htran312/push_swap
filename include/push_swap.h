/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:21:14 by htran-th          #+#    #+#             */
/*   Updated: 2024/11/16 18:21:55 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define MIN_INT -2147483648
# define MAX_INT 2147483647

// First, have a node
typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				value;
	int				rank;
	int				sent_flag;
}					t_node;

// Now, create a (linked) list of nodes (aka a stack)
typedef struct s_stack
{
	t_node			*top;
	t_node			*end;
	int				size;
}					t_stack;

typedef struct s_pushswap
{
	t_stack			*a;
	t_stack			*b;
}					t_pushswap;

typedef struct s_range
{
	int				start;
	int				end;
}					t_range;

// Parsing
char				**parse_input(int argc, char **argv, int *count);
void				error_cleanup(char ***array, char ***temp, int print_flag);
int					check_for_validity(char **array);
void				init_stack(t_pushswap *ps, char **array);

// Utils
void				free_arr(char **ar);
bool				is_sorted(t_stack *stack);
int					calculate_amount_of_chunk(int size);
bool				check_lower_half_sent(t_stack *stack, t_range *range,
						int median);
bool				check_upper_half_sent(t_stack *stack, t_range *range,
						int median);
void				update_chunk(t_stack *stack, t_range *range, int size);
void				free_stack(t_stack *stack);
void				free_stacks(t_pushswap *ps);

// Operations
void				swap(t_stack *stack);
void				sa(t_pushswap *ps);
void				sb(t_pushswap *ps);
void				ss(t_pushswap *ps);
void				pa(t_pushswap *ps);
void				pb(t_pushswap *ps);
void				rotate(t_stack *stack);
void				ra(t_pushswap *ps);
void				rb(t_pushswap *ps);
void				rr(t_pushswap *ps);
void				reverse_rotate(t_stack *stack);
void				rra(t_pushswap *ps);
void				rrb(t_pushswap *ps);
void				rrr(t_pushswap *ps);

// Algorithm
void				sort_three(t_pushswap *ps);
void				sort_five(t_pushswap *ps);
void				push_a_to_b(t_pushswap *ps, int size);
void				push_b_to_a(t_pushswap *ps, int size);

#endif
