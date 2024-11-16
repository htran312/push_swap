/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:32:11 by htran-th          #+#    #+#             */
/*   Updated: 2024/11/16 17:46:28 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_cleanup(char ***array, char ***temp, int print_flag)
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
    if (print_flag == 1)
    {
        ft_putendl_fd("Error", 2);
        exit(EXIT_FAILURE);
    }
    else
	    exit(EXIT_FAILURE);
}

static int	duplicate_array_element(char ***dst, char **src, int start, int len)
{
	int	i;

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

static char	**join_array(char **array, char **temp, int count, int temp_size)
{
	char	**new_array;
	int		old_size;

	old_size = count - temp_size;
	new_array = malloc(sizeof(char *) * (count + 1));
	if (!new_array)
		error_cleanup(&array, &temp, 0);
	if (!duplicate_array_element(&new_array, array, 0, old_size)
		|| !duplicate_array_element(&new_array, temp, old_size, temp_size))
	{
		free_arr(new_array);
		new_array = NULL;
		error_cleanup(&array, &temp, 0);
	}
	new_array[count] = NULL;
	free_arr(array);
	array = NULL;
	return (new_array);
}

char	**parse_input(int argc, char **argv, int *size)
{
	char	**array;
	char	**temp;
	int		i;
	int		j;

	array = NULL;
	i = 0;
	while (++i < argc)
	{
		temp = ft_split(argv[i], ' ');
		if (!temp || !temp[0])
			error_cleanup(&array, &temp, 0);
		j = -1;
		while (temp && temp[++j])
			(*size)++;
		array = join_array(array, temp, *size, j);
		if (!array)
			error_cleanup(&array, &temp, 0);
		free_arr(temp);
		temp = NULL;
	}
	if (check_for_validity(array) == 1)
		error_cleanup(&array, &temp, 1);
	return (array);
}
