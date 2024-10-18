/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:56:14 by htran-th          #+#    #+#             */
/*   Updated: 2024/10/18 20:47:35 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_data dt;
    t_pushswap ps;
    
    if (argc < 2)
        return (0);
    ft_bzero(&ps, sizeof(dt));
    parse_input(argc, argv, &dt, &ps);
    //init_stack(ps);
    //ft_bzero(&a, sizeof(a)); //keep it like this for now
    //if parse argv and init stack fails -> return (1)
    //if (argc == 2) && argv[1][0]

    
    
}