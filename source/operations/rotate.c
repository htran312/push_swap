/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:05:06 by htran-th          #+#    #+#             */
/*   Updated: 2024/11/03 06:02:06 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_stack *stack)
{
    t_node *first;
    
    if (!stack || stack->size < 2)
        return ;
    if (stack->size == 2)
    {
        swap(stack);
        return ;
    }
    first = stack->top;
    stack->top = first->next;
    stack->top->prev = NULL;
    //Link the previous last node to the rotated first node.
    stack->end->next = first;
    first->prev = stack->end;
    //Update pointers of the rotated first node to make it the new end.
    first->next = NULL;
    stack->end = first;
}
void ra(t_pushswap *ps)
{
    if (!ps->a || ps->a->size < 2)
        return ;
    rotate(ps->a);
    ft_putendl_fd("ra\n", 1);
}
void rb(t_pushswap *ps)
{
    if (!ps->b || ps->b->size < 2)
        return ;
    rotate(ps->b);
    ft_putendl_fd("rb\n", 1);
}
void rr(t_pushswap *ps)
{
    if (!ps->a || !ps->b|| ps->a->size < 2 || ps->b->size < 2)
        return ;
    rotate(ps->a);
    rotate(ps->b);
    ft_putendl_fd("rr\n", 1);
}