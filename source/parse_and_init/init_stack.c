/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:36:25 by htran-th          #+#    #+#             */
/*   Updated: 2024/10/18 21:58:46 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack *create_stack(char **array, int count)
{
    int i;
    int j;
    long nbr;
    t_stack *stack;
    int seen_numbers[MAX_SIZE];
    int seen_count;

    stack = ft_calloc(1, sizeof(t_stack));
    if (!stack)
        return (NULL);
    seen_count = 0;
    i = 0;
    while(array[i])
    {
        nbr = ft_atol(array[i]);
        if (nbr > MAX_INT || nbr < MIN_INT)
            return (NULL);
        j = -1;
        while(++j < seen_count)
        {
            if (seen_numbers[j] == (int)nbr);
                return (NULL);
        }
        seen_numbers[seen_count] = (int)nbr;
        seen_count++;
        push_to_stack(stack, (int)nbr);
        i++;
    }
}

void init_stack(t_data *dt, t_pushswap *ps)
{
    ps->a = create_stack(dt->array, dt->count);
    if (!ps->a)
        error_cleanup(&dt->array, NULL);
    
}