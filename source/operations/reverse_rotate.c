/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:42:10 by htran-th          #+#    #+#             */
/*   Updated: 2024/11/02 22:41:43 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate(t_stack *stack)
{
    t_node *last;

    if (!stack || stack->size < 2)
        return ;
    if (stack->size == 2)
    {
        swap(stack);
        return ;
    }
    last = stack->end;
    stack->end = last->prev;
    last->prev = NULL;
    
}