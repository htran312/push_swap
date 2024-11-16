/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa2b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 05:36:02 by htran-th          #+#    #+#             */
/*   Updated: 2024/11/16 15:36:16 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_chunk_range(t_range *range, int size)
{
	int	median;
	int	spread_radius;

	median = size / 2;
	spread_radius = size / calculate_amount_of_chunk(size);
	range->start = median - spread_radius;
	range->end = median + spread_radius;
	if (range->start < 0)
		range->start = 0;
	if (range->end > size - 3)
		range->end = size - 4;
}

static bool	check_chunk_sent(t_stack *stack, int start, int end)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp)
	{
		if (tmp->rank >= start && tmp->rank <= end)
		{
			if (tmp->sent_flag == 0)
				return (false);
		}
		tmp = tmp->next;
	}
	return (true);
}

void	push_a_to_b(t_pushswap *ps, int size)
{
	t_range	range;

	while (ps->a->size > 3)
	{
		set_chunk_range(&range, size);
		while (!check_chunk_sent(ps->a, range.start, range.end) && ps->a->size)
		{
			if (ps->a->top->rank >= range.start
				&& ps->a->top->rank <= range.end)
			{
				ps->a->top->sent_flag = 1;
				pb(ps);
				if (ps->b->top->rank < (size / 2))
					rb(ps);
			}
			else
				ra(ps);
			update_chunk(ps->a, &range, size);
		}
	}
	if (!is_sorted(ps->a))
		sort_three(ps);
}
