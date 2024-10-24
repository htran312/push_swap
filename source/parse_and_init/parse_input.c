/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:32:11 by htran-th          #+#    #+#             */
/*   Updated: 2024/10/24 22:37:19 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void error_cleanup(char ***array, char ***temp)
{
    if (*array)
    {
        free_arr(*array);
        *array = NULL;
    }
    if (*temp)
    {
        free_arr(*temp);
        *temp = NULL;
    }
    ft_putendl_fd("Error", 2);
    exit(EXIT_FAILURE);
}
static int duplicate_array_element(char ***dst, char **src, int start, int len)
{
    (void)src;
    int i;

    i = 0;
    while (i < len)
    {
        (*dst)[start + i] = ft_strdup(src[i]);
        if (!(*dst)[start + i])
        {
            free_arr(*dst);
            *dst = NULL;
            return (0);
        }
        i++;
    }
    return (1);
}
static char **join_array(char **array, char **temp, int count, int temp_size)
{
    char **new_array;
    int old_size;
    
    old_size = count - temp_size;
    new_array = malloc(sizeof(char *) * (count + 1));
    if (!new_array)
        error_cleanup(&array, &temp);
    if (!duplicate_array_element(&new_array, array, 0, old_size) ||
        !duplicate_array_element(&new_array, temp, old_size, temp_size))
    {
        free_arr(new_array);
        new_array = NULL;
        error_cleanup(&array, &temp);
    }
    new_array[count] = NULL;
    free_arr(array);
    array = NULL;
    return (new_array);
}

char **parse_input(int argc, char **argv, int *size)
{
    char **array;
    char **temp;
    int count;
    int i;
    int j;

    array = NULL;
    count = 0;
    i = 0;
    while (++i < argc)
    {
        temp = ft_split(argv[i], ' ');
        if (!temp || !temp[0])
            error_cleanup(&array, &temp);
        j = 0;
        while (temp && temp[j])
        {
            count++;
            j++;
        }
        array = join_array(array, temp, count, j);
        if (!array)
            error_cleanup(&array, &temp);
        free_arr(temp);
        temp = NULL;
    }
    if (check_for_validity(array) == 1)
        error_cleanup(&array, &temp);
    *size = count;
    return (array);
}
