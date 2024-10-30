/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:36:25 by htran-th          #+#    #+#             */
/*   Updated: 2024/10/30 22:07:56 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int smallest_among_us(t_stack *stack)
{
    /*
    looping through the stack, among those haven't get ranked
    (something->next != NULL (??) && node->rank == -1)
    */
    t_node *tmp;
    int small;

    tmp = stack->top; // we're at the first node
    printf("\nthe node at the current position is %d\n", tmp->value);
    small = tmp->value;
    printf("therefore small is now %d\n", small);
    while (tmp)
    {
        //Do stuff here
        if (tmp->rank == -1 && small > tmp->value)
        {
            printf("small is now %d and tmp->value is now %d\n", small, tmp->value);
            small = tmp->value;
        }
        tmp = tmp->next; // Traverse to the next node, until one point it'll be
                        // NULL (end node), consequently makes the condition fails
                        // and break ;
    }
    printf("small before returning is %d\n", small);
    return (small);
}

static void get_rank(t_stack *stack)
{
    /*
    ranking from 0 to size, smallest value gets 0
    continue until the biggest value gets rank size
    in a while loop from 0 < size:
    - needs a function to find the smallest value among those with rank == 0
    - find the node with that value (got from the function above), adds rank
    */
  t_node *tmp;

    int i;
    i = 0;
    while (i < stack->size)
    {
        tmp = stack->top;//it's pointing to the same thing top is pointing to
                            //which is the first node
        while (tmp)
        {
            if (tmp->rank == -1 && tmp->value == smallest_among_us(stack))
            {
                tmp->rank = i;
                break ;
            }
            tmp = tmp->next;//it's pointing to the same thing next is pointing to
                            //which is the node right after
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
        //printf("the first node value is now: %d\n", node->value);
    }
    else
    {
        node->prev = stack->end;
        stack->end->next = node;
        stack->end = node;
        //printf("the current node value is now: %d\n", node->value);
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
        //printf("node value before inserting is %d\n", node->value);
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
    //printf("the top node is %d\n", ps->a->top->value);
    //printf("the end node is %d\n", ps->a->end->value);
    printf("size of the stack is %d\n", ps->a->size);
}
