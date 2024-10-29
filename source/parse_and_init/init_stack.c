/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:36:25 by htran-th          #+#    #+#             */
/*   Updated: 2024/10/29 18:32:12 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void add_node_to_top(t_stack **stack, t_node **node)
{
    if (!stack || !node)
        return ;
    if ((*stack)->size == 0)
    {
        (*node)->next = NULL;
        (*stack)->top = *node;
        (*stack)->end = *node;
    }
    else
    {
        (*node)->next = (*stack)->top;
        (*stack)->top->prev = (*node);
        (*stack)->top = *node;
    }
    (*stack)->size++;
}

void init_stack(t_pushswap *ps, char **array)
{
    t_node *node;
    int i;
    
    ps->b = ft_calloc(1, sizeof(t_stack));
    ps->a = ft_calloc(1, sizeof(t_stack));
    if (!ps->a || !ps->b)
        return ;
    i = 0;
    while (array[i])
    {
        node = ft_calloc(1, sizeof(t_node));
        if(!node)
            return ;
        node->prev = NULL;
        node->value = ft_atoi(array[i]);
        add_node_to_top(&ps->a, &node);
        i++;
    }
    //populate index(rank)
}
