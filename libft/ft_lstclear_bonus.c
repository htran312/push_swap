/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 00:38:20 by htran-th          #+#    #+#             */
/*   Updated: 2024/05/15 15:14:15 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cur_node;
	t_list	*next_node;

	if (!lst || !del || !(*lst))
		return ;
	cur_node = (*lst);
	while (cur_node != NULL)
	{
		next_node = cur_node->next;
		del(cur_node->content);
		free(cur_node);
		cur_node = next_node;
	}
	*lst = NULL;
}
