/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:13:37 by lcompieg          #+#    #+#             */
/*   Updated: 2023/01/13 16:05:56 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	int		i;
	int		j;

	if (dest == NULL && size == 0)
		return (0);
	dest_len = ft_strlen(dest);
	i = 0;
	if (size < dest_len)
		return ((size_t)(size + ft_strlen(src)));
	while (dest[i] != '\0' && size > 0)
	{
		i++;
		size--;
	}
	j = 0;
	while (src[j] != '\0' && size > 1)
	{
		dest[i + j] = src[j];
		size--;
		j++;
	}
	if (size > 0)
		dest[i + j] = '\0';
	return ((size_t)(dest_len + ft_strlen(src)));
}
