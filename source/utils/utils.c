/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:40:59 by htran-th          #+#    #+#             */
/*   Updated: 2024/11/11 21:28:21 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long long	res;
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
		res = res * 10 + *str - '0';
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
// bool	is_sorted(t_stack *stack)
// {
// 	t_node	*temp;

// 	temp = stack->top;
// 	if (!stack || stack->size < 2)
//  		return (true);
// 	while (temp->prev)
// 	{
// 		if (temp->value > temp->prev->value)
// 			return (false);
// 		temp = temp->prev;
// 	}
// 	return (true);
// }

bool is_sorted(t_stack *stack)
{
	t_node *tmp;
	
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


//calculate how many chunk the input should be divided into
//if it's > 201 numbers ->13 chunks
//else -> 5 chunks
//above numbers are from testers. Let's try 2 chunks with < 50 numbers
int calculate_amount_of_chunk(int size)
{
    int chunk_amount;

    if (size < 201)
        chunk_amount = 5;
    else
        chunk_amount = 13;
    return (chunk_amount);
}
bool check_lower_half_sent(t_stack *stack, t_range *range, int median, int chunk_id)
{
	t_node *tmp;

	tmp = stack->top;
	while (tmp)
	{
		if (tmp->chunk_id == chunk_id && tmp->rank >= range->start && tmp->rank < median)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}
bool check_upper_half_sent(t_stack *stack, t_range *range, int median, int chunk_id)
{
	t_node *tmp;
	
	tmp = stack->end;
	while (tmp)
	{
		if (tmp->chunk_id != chunk_id && tmp->rank <= range->end && tmp->rank >= median)
			return (false);
		tmp = tmp->prev;
	}
	return (true);
}

void update_chunk(t_stack *stack, t_range *range, int size, int chunk_id)
{
	int median;
	int spread_radius;

	median = size / 2;
	spread_radius = size / calculate_amount_of_chunk(size);
	if (check_lower_half_sent(stack, range, median, chunk_id))
	{
		range->start -= spread_radius;
		// if (range->start < 0)
		// 	range->start = 0;
	}
	if (check_upper_half_sent(stack, range, median, chunk_id))
	{
		range->end += spread_radius;
		// if (range->end >= size - 3)
		// 	range->end = size - 4;
	}
	if (range->start < 0)
		range->start = 0;
	if (range->end >= size - 3)
		range->end = size - 4;
}


void print_stack(t_stack *stack)
{
	t_node *temp;
	
	temp = stack->top;
	while (temp)
    {
        printf("the node value is %d with rank %d anh chunk_id %d\n", temp->value, temp->rank, temp->chunk_id);
        temp = temp->next;
    }
	printf("size of the stack is %d\n", stack->size);
}