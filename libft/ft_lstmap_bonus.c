/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:18:16 by htran-th          #+#    #+#             */
/*   Updated: 2024/05/16 16:37:44 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_rest;
	t_list	*node_res;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	lst_rest = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		node_res = ft_lstnew(new_content);
		if (!node_res)
		{
			del(new_content);
			ft_lstclear(&lst_rest, (*del));
			return (lst_rest);
		}
		ft_lstadd_back(&lst_rest, node_res);
		lst = lst->next;
	}
	return (lst_rest);
}
