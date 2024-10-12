/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:32:11 by htran-th          #+#    #+#             */
/*   Updated: 2024/10/12 20:09:28 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int parse_input(int argc, char **argv, t_stack *a)
{
    char **array;
    char **temp;
    int i;
    
    array = NULL;
    i = 0;
    while (++i < argc)
    {
        temp = NULL;
        if (ft_strchr(argv[i], ' ') != NULL) //found space -> argv[i] is a string
        {
            //split the string and process each number
            temp = split_and_append(argv[i], temp);
        }
        else //argv[i] is not a string
        {
            //check if temp is valid
        }
        //either if argv[i] was a string or an int, join it to the array
    }
}