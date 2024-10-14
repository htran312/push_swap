/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:21:14 by htran-th          #+#    #+#             */
/*   Updated: 2024/10/14 22:43:52 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> 
# include "libft.h"

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

#endif