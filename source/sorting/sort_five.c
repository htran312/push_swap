/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 05:29:09 by htran-th          #+#    #+#             */
/*   Updated: 2024/11/06 15:31:09 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int lowest_rank(t_stack *stack)
{
    t_node *tmp;
    int lowest_rank;
    
    if (!stack->top)
        return (-1);
    tmp = stack->top;
    lowest_rank = tmp->rank;
    while (tmp)
    {
        if (tmp->rank < lowest_rank)
            lowest_rank = tmp->rank;
        tmp = tmp->next;
    }
    printf("lowest rank is now %d\n", lowest_rank);
    return (lowest_rank);
}

void sort_five(t_pushswap *ps)
{
    int current_lowest_rank;
    
    if (ps->a->size == 3)
    {
        sort_three(ps);
        return ;
    }
    current_lowest_rank = lowest_rank(ps->a);
    if (current_lowest_rank <= ps->a->size / 2)
    {
        while (ps->a->top->rank != current_lowest_rank)
        {
            ra(ps);
            print_stack(ps->a);
        }
    }
    else 
    {
        while (ps->a->top->rank != current_lowest_rank)
        {
            rra(ps);
            print_stack(ps->a);
        }
    }   
    pb(ps);
    print_stack(ps->b);
    sort_five(ps);
    while (ps->b->size)
        pa(ps);
}
