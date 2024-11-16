/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:32:05 by htran-th          #+#    #+#             */
/*   Updated: 2024/11/16 15:37:57 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arr(char **ar)
{
	int	i;

	i = 0;
	if (!ar)
		return ;
	while (ar[i])
	{
		free(ar[i]);
		ar[i] = NULL;
		i++;
	}
	free(ar);
}

void	free_stack(t_stack *stack)
{
	t_node	*tmp;
	t_node	*tmp_next;

	tmp = stack->top;
	while (tmp)
	{
		tmp_next = tmp->next;
		free(tmp);
		tmp = tmp_next;
	}
	free(stack);
}

void	free_stacks(t_pushswap *ps)
{
	if (ps->a)
	{
		free_stack(ps->a);
		ps->a = NULL;
	}
	if (ps->b)
	{
		free_stack(ps->b);
		ps->b = NULL;
	}
}
