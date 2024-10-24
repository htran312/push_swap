/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:56:14 by htran-th          #+#    #+#             */
/*   Updated: 2024/10/24 22:25:54 by htran-th         ###   ########.fr       */
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
    printf("count is now %d\n", count);
    //init_stack(ps);
    printf("Parsed array:\n");
    for (int i = 0; parsed_array[i]; i++)
    {
        printf("array[%d]: %s\n", i, parsed_array[i]);
        printf("number[%d]: %ld\n", i, ft_atol(parsed_array[i]));
    }
    free_arr(parsed_array);
    parsed_array = NULL;

    
    //if parse argv and init stack fails -> return (1)
    //if (argc == 2) && argv[1][0]

    
    
}