/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb2a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 05:36:14 by htran-th          #+#    #+#             */
/*   Updated: 2024/11/16 15:36:37 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_current_position(t_stack *stack, int current_max_rank)
{
	t_node	*tmp;
	int		i;

	tmp = stack->top;
	i = 0;
	if (!stack || !stack->top)
		return (-1);
	while (tmp)
	{
		if (tmp->sent_flag && tmp->rank == current_max_rank)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

void	push_b_to_a(t_pushswap *ps, int size)
{
	int	current_max_rank;
	int	current_position;

	current_max_rank = size - 1;
	while (ps->b->size)
	{
		current_position = check_current_position(ps->b, current_max_rank);
		if (ps->b->top->rank == current_max_rank)
		{
			ps->b->top->sent_flag = 0;
			pa(ps);
			current_max_rank--;
		}
		else if (current_position > (ps->b->size / 2))
			rrb(ps);
		else if (current_position > -1)
			rb(ps);
	}
}
