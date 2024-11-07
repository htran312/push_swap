/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa2b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 05:36:02 by htran-th          #+#    #+#             */
/*   Updated: 2024/11/07 21:45:13 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//calculate how many chunk the input should be divided into
//if it's > 201 numbers ->13 chunks
//else -> 5 chunks
//above numbers are from testers. Let's try 2 chunks with < 50 numbers
static int calculate_chunk_amount(int size)
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
static void set_chunk_range(int *start, int *end, int size)
{
    int median;
    int spread_radius;

    median = size / 2;
    spread_radius = calculate_chunk_amount(size);
    *start = median - spread_radius;
    *end = median + spread_radius;
    if (*start < 0)
        *start = 0;
    if (*end > size - 4)
        *end = size - 4;
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

void push_a_to_b(t_pushswap *ps)
{
    int start;
    int end;
    int chunk_id;
    
    while (ps->a->size > 3)
    {
        set_chunk_range(&start, &end, ps->a->size);
        while (!is_chunk_sent(ps->a, start, end, chunk_id) && ps->a->size)
        {
            
        }
        
        if (is_in_chunk(ps->a, &start, &end))
    }
    //send numbers inside the range to stack b. Probably needs to check if:
    //- Is there still number(s) inside the range
    //- Has this number been sent to stack b already?

    //calculate the range of the chunk, which depends on the median
    //
}