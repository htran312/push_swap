/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:56:14 by htran-th          #+#    #+#             */
/*   Updated: 2024/11/01 21:58:25 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_pushswap ps;
    int count;
    char **parsed_array;
    
    if (argc < 2)
        return (0);
    ft_bzero(&ps, sizeof(ps));
    count = 0;
    parsed_array = parse_input(argc, argv, &count);
    init_stack(&ps, parsed_array);
    
    free_arr(parsed_array);
    parsed_array = NULL;
    pb(&ps);
    pb(&ps);
    pb(&ps);
    pb(&ps);

    t_node *temp;
    
    temp = ps.a->top;
    printf("\nAFTER SORTING\n");
    printf("STACK A:\n");
    while (temp)
    {
        printf("the node value is %d with rank %d\n", temp->value, temp->rank);
        temp = temp->next;
    }
    printf("size of the stack is %d\n", ps.a->size);
    temp = ps.b->top;
    printf("STACK B:\n");
    while (temp)
    {
        printf("the node value is %d with rank %d\n", temp->value, temp->rank);
        temp = temp->next;
    }
    printf("size of the stack is %d\n", ps.b->size);

    



    
    
}
