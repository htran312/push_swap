/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:40:59 by htran-th          #+#    #+#             */
/*   Updated: 2024/10/16 12:17:18 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int is_white_space(char c)
{
    if (c >= 9 && c <= 13 || c == 32)
        return (1);
    else
        return (0);   
}*/
void	free_arr(char **ar)
{
	int	i;

	i = 0;
	if (!ar)
		return ;
	while (ar[i])
	{
		printf("Freeing array[%d]: %p\n", i, ar[i]);
		free (ar[i]);
		ar[i] = NULL;
		i++;
	}
	printf("Freeing array itself: %p\n", ar);
	free (ar);
}