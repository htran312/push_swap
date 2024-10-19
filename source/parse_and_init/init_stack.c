/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:36:25 by htran-th          #+#    #+#             */
/*   Updated: 2024/10/19 17:33:10 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long convert_and_check_range(char *str)
{
    long nbr;
    
    nbr = ft_atol(str);
    if (nbr > MAX_INT || nbr < MIN_INT)
    {
        //error handling
    }
    return (nbr);
}
static void check_for_duplicate(int *seen_numbers, int seen_count, int nbr)
{
    int i;

    i = 0;
    while(i < seen_count)
    {
        if (seen_numbers[i] == nbr)
        {
            //error handling
        }
    }
}
static void push_to_stack(t_stack *stack, int value)
{
    
}

static t_stack *create_stack(char **array, int count)
{
    t_stack *stack;
    long nbr;
    int i;
    int seen_numbers[MAX_SIZE];
    int seen_count;
    
    stack = ft_calloc(1, sizeof(t_stack));
    if (!stack)
        return (NULL);
    seen_count = 0;
    i = 0;
    while(array[i])
    {
        nbr = convert_and_check_range(array[i]);
        check_for_duplicate(seen_numbers, seen_count, nbr);
        seen_numbers[count++] = (int)nbr;
        push_to_stack(stack, nbr);
        i++;
    }
    return (stack);
}

void init_stack(t_data *dt, t_pushswap *ps)
{
    ps->a = create_stack(dt->array, dt->count);
    ps->b = ft_calloc(1, sizeof(t_stack));
    if (!ps->a || ps->b)
        error_cleanup(&dt->array, NULL);//error handling
    //initialize other members of stack a maybe?
    
}