/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:32:11 by htran-th          #+#    #+#             */
/*   Updated: 2024/10/16 19:06:54 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int is_valid_integer(char *str)
{
    (void)str;
    return (1);
}

static int error_cleanup(char ***array, char ***temp)
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
    return (1);
}

static char **join_array(char **array, char **temp, int count, int temp_size)
{
    char **new_array;
    int i;
    int j;
    int old_size;

    printf("count for malloc is now %d\n", (count + 1));
    new_array = malloc(sizeof(char *) * (count + 1));
    if(!new_array)// we probably will push the number to stack anyway
                    // instead of joining array so let's keep this
                    // error check like this for now
    {
        free_arr(temp);
        free_arr(array);
        return (NULL);
    }
    old_size = count - temp_size;
    printf("old size is now %d\n", old_size);
    i = 0;
    while (i < old_size)
    {
        printf("we're here\n");
        new_array[i] = ft_strdup(array[i]);
        i++;
    }
    j = 0;
    while (temp && temp[j])
    {
        printf("help!\n");
        new_array[i + j] = ft_strdup(temp[j]);
        j++;
    }
    new_array[i + j] = NULL;
    free_arr(array); //free the space that was holding the addresses of the strings
    array = NULL;
    return (new_array);
}

int parse_input(int argc, char **argv)
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
    printf("argc is now %d\n", argc);
    while (++i < argc)
    {
        if (ft_strchr(argv[i], ' ') != NULL)
        {
            temp = ft_split(argv[i], ' ');
            if (!temp || !temp[0])
                return (error_cleanup(&array, &temp));
            j = 0;
            while (temp && temp[j]) //&& check if it's a valid integer 
            {
                if (!is_valid_integer(temp[j]))
                    return (error_cleanup(&array, &temp));
                count++;
                printf("count after split is now %d\n", count);
                j++;
            }
            array = join_array(array, temp, count, j); //join the result here
            if (!array)
                return (error_cleanup(&array, &temp));
            free_arr(temp);
            temp = NULL;
            printf("printing after split\n");
            for (int l = 0; array && array[l]; l++)
                printf("array[%d]: %s\n", l, array[l]);
        }
        else //check if argv[i] is a valid integer then count++
        {
            if (!is_valid_integer(argv[i]))
                return (error_cleanup(&array, NULL));
            count++;
            printf("count after the integer is now %d\n", count);
            temp = malloc(sizeof(char *) * 2);
            temp[0] = ft_strdup(argv[i]);
            temp[1] = NULL;
            array = join_array(array, temp, count, 1);
            if (!array)
                return (error_cleanup(&array, NULL));
            free_arr(temp);
            temp = NULL;
            printf("printing after appending integer\n");
            for (int m = 0; array && array[m]; m++)
                printf("array[%d]: %s\n", m, array[m]);
        }
    }
    printf("we're printing the final array\n");
    for (int k = 0; array && array[k]; k++)
        printf("array[%d]: %s\n", k, array[k]);

    free_arr(array); //actually, we need to init_stack before reaching this point
    return (0);
}
