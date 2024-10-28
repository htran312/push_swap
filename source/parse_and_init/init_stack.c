/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:36:25 by htran-th          #+#    #+#             */
/*   Updated: 2024/10/28 22:00:04 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void insert_node(t_stack **stack, t_node **node)
{
    if (!stack || !node)
        return ;
    if ((*stack)->size == 0)
    {
        (*node)->next = NULL;
        (*stack)->top = *node;
        (*stack)->end = *node;
        printf("value of the first node is %d\n", (*stack)->top->value);
        (*stack)->size++;
        return ;
    }
    (*stack)->end = find_last_node()
    
    
    (*stack)->top->prev = *node;
    (*node)->next = (*stack)->top;
    (*stack)->top->next = NULL;
    (*stack)->size++;
    printf("value of the current node is %d\n", (*stack)->top->value);
}


void init_stack(t_pushswap *ps, char **array)
{
    t_node *node;
    int i;
    
    ps->b = ft_calloc(1, sizeof(t_stack));
    ps->a = ft_calloc(1, sizeof(t_stack));
    if (!ps->a || !ps->b)
        return ;
    i = 0;
    while (array[i])
    {
        node = ft_calloc(1, sizeof(t_node));
        if(!node)
            return ;
        node->prev = NULL;
        node->value = ft_atoi(array[i]);
        printf("node value before inserting is %d\n", node->value);
        insert_node(&ps->a, &node);
        i++;
    }
    printf("top value is %d\n", ps->a->top->value);
    printf("end value is %d\n", ps->a->end->value);
    printf("stack size is %d\n", ps->a->size);
}
