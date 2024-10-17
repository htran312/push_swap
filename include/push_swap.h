/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:21:14 by htran-th          #+#    #+#             */
/*   Updated: 2024/10/17 21:53:51 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

# define MIN_INT -2147483648
# define MAX_INT 2147483647

// First, have a node
typedef struct s_node
{
    int value;
    struct s_node *prev;
    struct s_node *next;
}   t_node;

// Now, create a (linked) list of nodes (aka a stack)
typedef struct s_stack
{
    t_node *top;
}   t_stack;

void parse_input(int argc, char **argv);
void	free_arr(char **ar);
int is_valid_integer(char *str);

#endif