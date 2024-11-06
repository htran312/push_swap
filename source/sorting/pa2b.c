/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa2b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 05:36:02 by htran-th          #+#    #+#             */
/*   Updated: 2024/11/06 20:23:15 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//calculate how many chunk the input should be divided into
//if it's > 201 numbers ->13 chunks
//else -> 5 chunks
static int calculate_chunk_amount(t_pushswap *ps)
{
    int chunk_amount;

    if (ps->a->size > 201)
        chunk_amount = 13;
    else
        chunk_amount = 5;
    return (chunk_amount);
}
//function to set the range of the chunk
//how large is the chunk? Depends on the size (of the input)
//calculate "the radius of the spreading from the median" (how far the index
//should be taken into the chunk. For example: take 2 numbers from above and
//below the median)
static void calculate_chunk_range()
{
    
}


void push_a_to_b(t_pushswap *ps)
{
    int chunk_start;
    int chunk_end;
    int size;
    //send numbers inside the range to stack b. Probably needs to check if:
    //- Is there still number(s) inside the range
    //- Has this number been sent to stack b already?

    //calculate the range of the chunk, which depends on the median
    //
}