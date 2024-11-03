/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:42:10 by htran-th          #+#    #+#             */
/*   Updated: 2024/11/03 03:34:43 by htran-th         ###   ########.fr       */
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
    stack->end->next = NULL;
    last->prev = NULL;
    last->next = stack->top;
    stack->top->prev = last;
    stack->top = last;
}
void rra(t_stack *stack)
{
    if (!stack || stack->size < 2)
        return ;
    reverse_rotate(stack);
    ft_putendl_fd("rra\n", 1);
}
void rrb(t_stack *stack)
{
    if (!stack || stack->size < 2)
        return ;
    reverse_rotate(stack);
    ft_putendl_fd("rrb\n", 1);
}
void rrr(t_pushswap *ps)
{
    if (!ps->a || ps->b || ps->a->size < 2 || ps->b->size < 2)
        return ;
    reverse_rotate(ps->a);
    reverse_rotate(ps->b);
    ft_putendl_fd("rrr\n", 1);
}