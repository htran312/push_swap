/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb2a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 05:36:14 by htran-th          #+#    #+#             */
/*   Updated: 2024/11/10 17:18:57 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int find_max_rank(t_stack *stack) {
    t_node *current = stack->top;
    int max_rank = current->rank;

    while (current) {
        if (current->rank > max_rank)
            max_rank = current->rank;
        current = current->next;
    }
    return max_rank;
}


void push_b_to_a(t_pushswap *ps, int size) {
    int max_rank;

    while (ps->b->size > 0) {
        // Step 1: Find the largest rank in stack B
        max_rank = find_max_rank(ps->b);

        // Step 2: Move the largest element to the top of stack B
        while (ps->b->top->rank != max_rank) {
            if (ps->b->top->rank < size / 2)
                rb(ps);   // Rotate if max_rank is in the lower half
            else
                rrb(ps);  // Reverse rotate if max_rank is in the upper half
        }

        // Step 3: Push the top element of stack B (the largest element) to stack A
        pa(ps);
    }
}
