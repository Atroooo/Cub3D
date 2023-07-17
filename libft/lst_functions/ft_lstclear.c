/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:25:02 by lcompieg          #+#    #+#             */
/*   Updated: 2023/07/17 17:32:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		(*del)((*lst)->content);
		current = *lst;
		*lst = (*lst)->next;
		free(current);
	}
}
