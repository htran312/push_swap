/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:32:11 by htran-th          #+#    #+#             */
/*   Updated: 2024/10/18 21:26:59 by htran-th         ###   ########.fr       */
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
static void duplicate_array_element(char ***dst, char **src, int start, int len, t_data *dt)
{
    int i;

    i = 0;
    while (i < len)
    {
        (*dst)[start + i] = ft_strdup(src[i]);
        if (!(*dst)[start + i])
        {
            free_arr(*dst);
            error_cleanup(&dt->array, &dt->temp);
        }
        i++;
    }
}
static char **join_array(t_data *dt, int temp_size)
{
    char **new_array;
    int old_size;
    
    old_size = dt->count - temp_size;
    new_array = malloc(sizeof(char *) * (dt->count + 1));
    if (!new_array)
        error_cleanup(&dt->array, &dt->temp);
    duplicate_array_element(&new_array, dt->array, 0, old_size, dt);
    duplicate_array_element(&new_array, dt->temp, old_size, temp_size, dt);
    new_array[dt->count] = NULL;
    free_arr(dt->array);
    dt->array = NULL;

    return (new_array);
}
void parse_input(int argc, char **argv, t_data *dt, t_pushswap *ps)
{
    int i;
    int j;

    i = 0;
    while (++i < argc)
    {
        dt->temp = ft_split(argv[i], ' ');
        if (!dt->temp || !dt->temp[0])
            error_cleanup(&dt->array, &dt->temp);
        j = 0;
        while (dt->temp && dt->temp[j])
        {
            if (!is_integer(dt->temp[j]))
                error_cleanup(&dt->array, &dt->temp);
            dt->count++;
            j++;
        }
        dt->array = join_array(dt, j);
        if (!dt->array)
            error_cleanup(&dt->array, &dt->temp);
        free_arr(dt->temp);
        dt->temp = NULL;
    }
    printf("we're printing the final array\n");
    for (int k = 0; dt->array && dt->array[k]; k++)
        printf("array[%d]: %s\n", k, dt->array[k]);
    init_stack(dt, ps);
    free_arr(dt->array); //actually, we need to init_stack before reaching this point
}
