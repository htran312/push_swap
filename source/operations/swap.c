/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:50:55 by htran-th          #+#    #+#             */
/*   Updated: 2024/11/02 17:25:09 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack *stack)
{
    t_node *first;
    t_node *second;
    
    if ((!stack) || stack->size < 2)
        return ;
    first = stack->top;
    second = first->next;
    second->prev = NULL;
    stack->top = second;
    first->next = second->next;
    if (first->next)
        second->next->prev = first;
    second->next = first;
    first->prev = second;
    if (stack->size == 2)
        stack->end = first;
}
void sa(t_stack *stack)
{
    if ((!stack) || stack->size < 2)
        return ;
    swap(stack);
    ft_putendl_fd("sa\n", 1);
}
void sb(t_stack *stack)
{
    if ((!stack) || stack->size < 2)
        return ;
    swap(stack);
    ft_putendl_fd("sb\n", 1);
}
void ss(t_pushswap *ps)
{
    if (!ps->a || !ps->b || ps->a->size < 2  || ps->b->size < 2)
        return ;
    swap(ps->a);
    swap(ps->b);
    ft_putendl_fd("ss\n", 1);
}