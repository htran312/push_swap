/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:36:25 by htran-th          #+#    #+#             */
/*   Updated: 2024/10/31 19:06:56 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int smallest_among_us(t_stack *stack)
{
    t_node *tmp;
    int small;

    tmp = stack->top;
    small = MAX_INT;
    while (tmp)
    {
        if (tmp->rank == -1 && small > tmp->value)
            small = tmp->value;
        tmp = tmp->next;
    }
    return (small);
}

static void get_rank(t_stack *stack)
{
    t_node *tmp;
    int i;
    
    i = 0;
    while (i < stack->size)
    {
        tmp = stack->top;
        while (tmp)
        {
            if (tmp->rank == -1 && tmp->value == smallest_among_us(stack))
            {
                tmp->rank = i;
                break ;
            }
            tmp = tmp->next;
        }
        i++;
    }
}
static void add_node_to_end(t_stack *stack, t_node *node)
{
    if (!stack || !node)
    {
        printf("stack is empty\n");
        return ;
    }
    if (stack->size == 0)
    {
        node->next = NULL;
        stack->top = node;
        stack->end = node;
    }
    else
    {
        node->prev = stack->end;
        stack->end->next = node;
        stack->end = node;
    }
    stack->size++;
}


void init_stack(t_pushswap *ps, char **array)
{
    t_node *node;
    int i;
    
    ps->b = ft_calloc(1, sizeof(t_stack));
    ps->a = ft_calloc(1, sizeof(t_stack));
    if (!ps->a || !ps->b)
        return ;//do error handling por favor!
    i = 0;
    while (array[i])
    {
        node = ft_calloc(1, sizeof(t_node));
        if(!node)
            return ;//error handling por favor
        node->next = NULL;
        node->value = ft_atoi(array[i]);
        node->rank = -1;
        add_node_to_end(ps->a, node);
        i++;
    }
    get_rank(ps->a);
    t_node *temp;
    temp = ps->a->top;
    while (temp)
    {
        printf("the node value is %d with rank %d\n", temp->value, temp->rank);
        temp = temp->next;
    }
    printf("size of the stack is %d\n", ps->a->size);

}
