/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:23:17 by lcompieg          #+#    #+#             */
/*   Updated: 2023/07/21 15:54:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	unsigned int	j;
	const char		*temp;

	i = 0;
	while (i < ft_strlen(s) + 1)
	{
		if (s[i] == (char)c)
		{
			j = i;
			while (j < ft_strlen(s) + 1)
			{
				if (s[j] == (char)c)
					temp = (&((char *)s)[j]);
				j++;
			}
			return ((char *)temp);
		}
		else
			temp = NULL;
		i++;
	}
	return ((char *)temp);
}
