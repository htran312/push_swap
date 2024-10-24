/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:36:25 by htran-th          #+#    #+#             */
/*   Updated: 2024/10/24 18:35:06 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int check_for_duplicate(int *seen_numbers, int seen_count, int nbr)
{
    int i;

    i = 0;
    while(i < seen_count)
    {
        if (seen_numbers[i] == nbr)
            return (0);
        i++;
    }
    return (1);
}
static void push_to_stack(t_stack *stack, int value)
{
    t_node *new_node;
    
    new_node = ft_calloc(1, sizeof(t_node));
    if (!new_node)
    {
        //free stack
        error_cleanup()
    }
}

static t_stack *create_stack(t_data *dt)
{
    t_stack *stack;
    long nbr;
    int i;
    int seen_numbers[MAX_SIZE];
    int seen_count;
    
    stack = ft_calloc(1, sizeof(t_stack));
    if (!stack)
        return (NULL);
    ft_bzero(seen_numbers, sizeof(seen_numbers));
    seen_count = 0;
    i = 0;
    while(dt->array[i])
    {
        nbr = ft_atol(dt->array[i]);
        if (!check_for_duplicate(seen_numbers, seen_count, nbr))
        {
            //free stack;
            //return (NULL);
        }
        seen_numbers[seen_count++] = (int)nbr;
        push_to_stack(stack, nbr);
        i++;
    }
    return (stack);
}

void init_stack(t_data *dt, t_pushswap *ps)
{
    ps->a = create_stack(dt);
    ps->b = ft_calloc(1, sizeof(t_stack));
    if (!ps->a || !ps->b)
        error_cleanup(&dt->array, NULL);//error handling
    //initialize other members of stack a maybe?
    
}