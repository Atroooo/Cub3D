/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:12:19 by lcompieg          #+#    #+#             */
/*   Updated: 2023/01/13 16:05:56 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0 ;
	if (n == 0)
		return (0);
	while ((unsigned)s1[i] && (unsigned)s2[i] && i < n - 1
		&& (unsigned)s1[i] == (unsigned)s2[i])
		i++;
	if ((unsigned)s1[i] > (unsigned)s2[i])
		return (1);
	else if ((unsigned)s1[i] == (unsigned)s2[i])
		return (0);
	return (-1);
}
