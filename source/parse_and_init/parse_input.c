/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:32:11 by htran-th          #+#    #+#             */
/*   Updated: 2024/10/17 21:19:05 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void error_cleanup(char ***array, char ***temp)
{
    printf("help!\n");
    if (*array)
    {
        free_arr(*array);
        *array = NULL;
    }
    printf("help2!\n");
    if (*temp)
    {
        free_arr(*temp);
        *temp = NULL;
    }
    ft_printf("Error\n");
    exit(EXIT_FAILURE);
}

static char **join_array(char **array, char **temp, int count, int temp_size)
{
    char **new_array;
    int i;
    int j;
    int old_size;

    new_array = malloc(sizeof(char *) * (count + 1));
    if(!new_array)
        error_cleanup(&array, &temp);
    old_size = count - temp_size;
    i = 0;
    while (i < old_size)
    {
        new_array[i] = ft_strdup(array[i]);
        if (!new_array[i])
        {
            free_arr(new_array);
            new_array = NULL;
            error_cleanup(&array, &temp);
        }
        i++;
    }
    j = 0;
    while (temp && temp[j])
    {
        new_array[i + j] = ft_strdup(temp[j]);
        if (!new_array[i])
        {
            free_arr(new_array);
            new_array = NULL;
            error_cleanup(&array, &temp);
        }
        j++;
    }
    new_array[i + j] = NULL;
    free_arr(array);
    array = NULL;
    return (new_array);
}

void parse_input(int argc, char **argv)
{
    char **array;
    char **temp;
    int count;
    int i;
    int j;
    //long *nbr;  
    
    array = NULL;
    count = 0;
    i = 0;
    while (++i < argc)
    {
        if (ft_strchr(argv[i], ' ') != NULL)
        {
            temp = ft_split(argv[i], ' ');
            if (!temp || !temp[0])
                error_cleanup(&array, &temp);
            j = 0;
            while (temp && temp[j])
            {
                if (!is_valid_integer(temp[j]))
                    error_cleanup(&array, &temp);
                count++;
                j++;
            }
            array = join_array(array, temp, count, j);
            if (!array)
                error_cleanup(&array, &temp);
            free_arr(temp);
            temp = NULL;
        }
        else //check if argv[i] is a valid integer then count++
        {
            temp = malloc(sizeof(char *) * 2);
            temp[0] = ft_strdup(argv[i]);
            if (!temp || !temp[0])
                error_cleanup(&array, &temp);
            temp[1] = NULL;
            if (!is_valid_integer(argv[i]))
                error_cleanup(&array, &temp);
            count++;
            array = join_array(array, temp, count, 1);
            if (!array)
                error_cleanup(&array, &temp);
            free_arr(temp);
            temp = NULL;
        }
    }
    printf("we're printing the final array\n");
    for (int k = 0; array && array[k]; k++)
        printf("array[%d]: %s\n", k, array[k]);

    free_arr(array); //actually, we need to init_stack before reaching this point
}
