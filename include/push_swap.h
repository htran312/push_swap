/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:21:14 by htran-th          #+#    #+#             */
/*   Updated: 2024/11/03 04:25:25 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

# define MIN_INT -2147483648
# define MAX_INT 2147483647

# define MAX_SIZE 1024

// First, have a node
typedef struct s_node
{
    struct s_node *prev;
    struct s_node *next;
    int value;
    int rank;
}   t_node;

// Now, create a (linked) list of nodes (aka a stack)
typedef struct s_stack
{
    t_node *top;
    t_node *end;
    int size;
}   t_stack;

typedef struct s_pushswap
{
    t_stack *a;
    t_stack *b;
}   t_pushswap;

char **parse_input(int argc, char **argv, int *count);
void	free_arr(char **ar);
void error_cleanup(char ***array, char ***temp);
int check_for_validity(char **array);
long	ft_atol(const char *str);
void init_stack(t_pushswap *ps, char **array);

// Operations
void swap(t_stack *stack);
void sa(t_stack *stack);
void sb(t_stack *stack);
void ss(t_pushswap *ps);
void pa(t_pushswap *ps);
void pb(t_pushswap *ps);
void rotate(t_stack *stack);
void ra(t_stack *stack);
void rb(t_stack *stack);
void rr(t_pushswap *ps);
void reverse_rotate(t_stack *stack);
void rra(t_stack *stack);
void rrb(t_stack *stack);
void rrr(t_pushswap *ps);
void sort_three(t_stack *stack);

#endif