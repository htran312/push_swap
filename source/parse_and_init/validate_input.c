/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:19:47 by htran-th          #+#    #+#             */
/*   Updated: 2024/11/16 15:35:41 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_range(char *str)
{
	long	nbr;

	nbr = ft_atol(str);
	if (nbr > MAX_INT || nbr < MIN_INT)
		return (0);
	return (1);
}

static int	check_character_and_sign(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[1] == '+' || str[1] == '-' || str[1] == '\0')
			return (0);
		i++;
	}
	while (str[i] != '\0')
	{
		if (!ft_strchr("0123456789", str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_for_validity(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		if (!array[i] || array[i][0] == '\0')
			return (1);
		if (!check_character_and_sign(array[i]))
			return (1);
		if (!check_range(array[i]))
			return (1);
		j = 0;
		while (j < i)
		{
			if (ft_atoi(array[j]) == ft_atoi(array[i]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
