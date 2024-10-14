/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:32:11 by htran-th          #+#    #+#             */
/*   Updated: 2024/10/14 22:50:44 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char **join_array(char **array, char **temp, int count, int temp_size)
{
    char **new_array;
    int i;
    int j;
    int old_size;

    new_array = malloc(sizeof(char *) * (count + 1));
    //error check
    old_size = count - temp_size;
    i = 0;
    while (i < old_size)
    {
        *new_array[i]
    }
    j = 0;
    while (temp && temp[j])
    {
        new_array[i + ]
    }
    
}

int parse_input(int argc, char **argv, t_stack *a)
{
    char **array;
    char **temp;
    int count;
    int i;
    int j;
    long *nbr;  
    
    array = NULL;
    count = 0;
    i = 0;
    while (++i < argc)
    {
        if (ft_strchr(argv[i], ' ') != NULL)
        {
            temp = ft_split(argv[i], ' ');
            if (!temp || !temp[i])
            {
                return (1);
            }
            j = 0;
            while (temp[j]) //&& check if it's a valid integer 
            {
                if (!is_valid_integer(temp[j]))
                {
                    free_arr(temp);
                    return (1);
                }
                count++;
                j++;
            }
            array = join_array(array, temp, count, j); //join the result here
            free_arr(temp);
            temp = NULL;
        }
        else //check if argv[i] is a valid integer then count++
        {
            if (!is_valid_integer(argv[i]))
                return (1);
            count++;
            array = join_array(array, &argv[i], count, 1);
        } 
    }
    
    //Now we have count, malloc enough space for the whole input
    
    
    return (0);
}
