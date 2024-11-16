/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:40:59 by htran-th          #+#    #+#             */
/*   Updated: 2024/11/16 15:39:06 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	if (!stack || stack->size < 2)
		return (true);
	while (tmp)
	{
		if (tmp->next && tmp->value > tmp->next->value)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

int	calculate_amount_of_chunk(int size)
{
	int	chunk_amount;

	if (size < 201)
		chunk_amount = 5;
	else
		chunk_amount = 11;
	return (chunk_amount);
}

bool	check_lower_half_sent(t_stack *stack, t_range *range, int median)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp)
	{
		if (tmp->sent_flag != 1 && tmp->rank >= range->start
			&& tmp->rank < median)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

bool	check_upper_half_sent(t_stack *stack, t_range *range, int median)
{
	t_node	*tmp;

	tmp = stack->end;
	while (tmp)
	{
		if (tmp->sent_flag != 1 && tmp->rank <= range->end
			&& tmp->rank >= median)
			return (false);
		tmp = tmp->prev;
	}
	return (true);
}

void	update_chunk(t_stack *stack, t_range *range, int size)
{
	int	median;
	int	spread_radius;

	median = size / 2;
	spread_radius = size / calculate_amount_of_chunk(size);
	if (check_lower_half_sent(stack, range, median))
		range->start -= spread_radius;
	if (check_upper_half_sent(stack, range, median))
		range->end += spread_radius;
	if (range->start < 0)
		range->start = 0;
	if (range->end >= size - 3)
		range->end = size - 4;
}
