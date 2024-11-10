/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa2b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 05:36:02 by htran-th          #+#    #+#             */
/*   Updated: 2024/11/10 22:24:24 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//function to set the range of the chunk
//how large is the chunk? Depends on the size (of the input)
//calculate "the radius of the spreading from the median" (how far the index
//should be taken into the chunk. For example: take 2 numbers from above and
//below the median)
static void set_chunk_range(t_range *range, int size)
{
    int median;
    int spread_radius;

    median = size / 2;
    spread_radius = size / calculate_amount_of_chunk(size);
    range->start = median - spread_radius;
    range->end = median + spread_radius;
    if (range->start < 0)
        range->start = 0;
    if (range->end > size - 4)
        range->end = size - 4;
}
// static bool is_in_chunk(t_stack *stack, int *start, int *end)
// {
//     int rank;
    
//     rank = stack->top->rank;
//     if (rank >= *start && rank <= *end)
//         return (true);
//     else
//         return (false);
// }

/*
Check if there's any node still left in the chunk.
*/
static bool check_chunk_sent(t_stack *stack, int start, int end, int chunk_id)
{
    t_node *tmp;

    tmp = stack->top;
    while (tmp)
    {
        if (tmp->rank >= start && tmp->rank <= end)
        {
            if (tmp->chunk_id != chunk_id)
                return (false);
        }
        tmp = tmp->next;
    }
    return (true);
}

void push_a_to_b(t_pushswap *ps, int size)
{
    // int start;
    // int end;
    t_range range;
    int chunk_id;
    
    chunk_id = 0;
    set_chunk_range(&range, size);
    while (ps->a->size > 3)
    {
        while (!check_chunk_sent(ps->a, range.start, range.end, chunk_id) && ps->a->size)
        {
            if (ps->a->top->rank >= range.start && ps->a->top->rank <= range.end)
            {
                ps->a->top->chunk_id = chunk_id;
                pb(ps);
                if (ps->b->top->rank < (size / 2))
                    rb(ps);
            }
            else
                ra(ps);
            update_chunk(ps->a, &range, size, chunk_id);
        }
        chunk_id++;
    }
    if (!is_sorted(ps->a))
        sort_three(ps);
}
