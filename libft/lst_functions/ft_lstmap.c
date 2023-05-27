/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:37:51 by lcompieg          #+#    #+#             */
/*   Updated: 2023/01/13 16:05:56 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
	t_list	*newlist;

	newlist = NULL;
	if (lst == NULL)
		return (NULL);
	else
	{
		while (lst != NULL)
		{
			ft_lstadd_back(&newlist, ft_lstnew((*f)(lst->content)));
			if (!newlist)
			{
				ft_lstclear(&newlist, *del);
				return (NULL);
			}
			lst = lst->next;
		}
		return (newlist);
	}
}
