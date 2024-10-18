/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:21:14 by htran-th          #+#    #+#             */
/*   Updated: 2024/10/18 21:46:51 by htran-th         ###   ########.fr       */
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
    int value;
    int index;
    struct s_node *prev;
    struct s_node *next;
}   t_node;

// Now, create a (linked) list of nodes (aka a stack)
typedef struct s_stack
{
    t_node *top;
    t_node *end;
    int size;
}   t_stack;

typedef struct s_data
{
    char **array;
    char **temp;
    int count;
}   t_data;

typedef struct s_pushswap
{
    t_stack *a;
    t_stack *b;
}   t_pushswap;

void parse_input(int argc, char **argv, t_data *dt, t_pushswap *ps);
void	free_arr(char **ar);
void error_cleanup(char ***array, char ***temp);
int is_integer(char *str);
long	ft_atol(const char *str);
void init_stack(t_data *dt, t_pushswap *ps);

#endif