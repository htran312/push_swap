/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:40:59 by htran-th          #+#    #+#             */
/*   Updated: 2024/10/18 16:15:54 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long long	res;
	long long	check;
	int			sign;

	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		check = res * 10 + *str - '0';
		if (check / 10 != res && sign == -1)
			return (0);
		if (check / 10 != res && sign == 1)
			return (-1);
		res = check;
		str++;
	}
	return (sign * res);
}
void	free_arr(char **ar)
{
	int	i;

	i = 0;
	if (!ar)
		return ;
	while (ar[i])
	{
		free (ar[i]);
		ar[i] = NULL;
		i++;
	}
	free (ar);
}