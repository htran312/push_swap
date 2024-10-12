/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:32:11 by htran-th          #+#    #+#             */
/*   Updated: 2024/10/12 18:50:18 by htran-th         ###   ########.fr       */
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
            if (!temp)
                return (1);
        }
        else //argv[i] is a normal int
        {
            //atoi that int to temp
            //check if temp is valid
        }
        //either if argv[i] was a string or an int, join it to the array
        array = ft_strjoin_gnl(array, temp);
    }
}