/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:00:41 by htran-th          #+#    #+#             */
/*   Updated: 2024/11/03 06:07:41 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_pushswap *ps)
{
    int first;
    int second;
    int third;

    first = ps->a->top->rank;
    second = ps->a->top->next->rank;
    third = ps->a->top->next->next->rank;
	if (third > first && first > second)
		sa(ps);
    else if (first > second && second > third)
	{
		sa(ps);
		rra(ps);
	}
	else if (first > third && third > second)
		ra(ps);
	else if (second > third && third > first)
	{
		sa(ps);
		ra(ps);
	}  
	else if (second > first && first > third)
		rra(ps);
}
