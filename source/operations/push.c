/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:51:20 by htran-th          #+#    #+#             */
/*   Updated: 2024/11/01 22:04:19 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push(t_stack *src, t_stack *des)
{
    t_node *tmp_s;
    
    if (!src || src->size == 0 || !des)
        return ;
    tmp_s = src->top;
    src->top = tmp_s->next;
    if (src->size == 1)
        src->end = NULL;
    else
        src->top->prev = NULL;
    if (des->size == 0)
    {
        des->top = tmp_s;
        des->end = tmp_s;
        tmp_s->next = NULL;
    }
    else
    {
        tmp_s->next = des->top;
        des->top->prev = tmp_s;
        des->top = tmp_s;
    }
    src->size--;
    des->size++;
}
void pa(t_pushswap *ps)
{
    if (!ps->b || ps->b->size == 0)
        return ;
    push(ps->b, ps->a);
    ft_putendl_fd("pa\n", 1);
}
void pb(t_pushswap *ps)
{
    if (!ps->a || ps->a->size == 0)
        return ;
    push(ps->a, ps->b);
    ft_putendl_fd("pb\n", 1);
}