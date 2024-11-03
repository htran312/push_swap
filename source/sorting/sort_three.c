/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:00:41 by htran-th          #+#    #+#             */
/*   Updated: 2024/11/03 04:21:50 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_stack *stack)
{
    int first;
    int second;
    int third;

    first = stack->top->rank;
    second = stack->top->next->rank;
    third = stack->top->next->next->rank;
	if (third > first && first > second)
		sa(stack);
    else if (first > second && second > third)
	{
		sa(stack);
		rra(stack);
	}
	else if (first > third && third > second)
		ra(stack);
	else if (second > third && third > first)
	{
		sa(stack);
		ra(stack);
	}  
	else if (second > first && first > third)
		rra(stack);
}
