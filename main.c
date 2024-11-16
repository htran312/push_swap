/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:56:14 by htran-th          #+#    #+#             */
/*   Updated: 2024/11/16 15:10:38 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack(t_pushswap *ps)
{
	if (ps->a->size == 2)
		sa(ps);
	else if (ps->a->size == 3)
		sort_three(ps);
	else if (ps->a->size <= 5)
		sort_five(ps);
	else if (ps->a->size > 5)
	{
		push_a_to_b(ps, ps->a->size);
		push_b_to_a(ps, ps->b->size);
	}
}

int	main(int argc, char **argv)
{
	t_pushswap	ps;
	int			count;
	char		**parsed_array;

	if (argc < 2)
		return (0);
	ft_bzero(&ps, sizeof(ps));
	count = 0;
	parsed_array = parse_input(argc, argv, &count);
	if (!parsed_array)
		return (1);
	init_stack(&ps, parsed_array);
	free_arr(parsed_array);
	parsed_array = NULL;
	if (ps.a && ps.b)
	{
		if (!is_sorted(ps.a))
			sort_stack(&ps);
	}
	free_stacks(&ps);
	return (0);
}
