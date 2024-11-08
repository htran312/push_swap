/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa2b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 05:36:02 by htran-th          #+#    #+#             */
/*   Updated: 2024/11/08 22:51:13 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//calculate how many chunk the input should be divided into
//if it's > 201 numbers ->13 chunks
//else -> 5 chunks
//above numbers are from testers. Let's try 2 chunks with < 50 numbers
static int calculate_amount_of_chunk(int size)
{
    int chunk_amount;
    
    if (size < 50)
        chunk_amount = 2;
    else if (size < 200)
        chunk_amount = 5;
    else
        chunk_amount = 13;
    return (chunk_amount);
}
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
static bool is_chunk_sent(t_stack *stack, int start, int end, int chunk_id)
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
    while (ps->a->size > 3)
    {
        set_chunk_range(&range, size);
        while (!is_chunk_sent(ps->a, range.start, range.end, chunk_id) && ps->a->size > 3)
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
