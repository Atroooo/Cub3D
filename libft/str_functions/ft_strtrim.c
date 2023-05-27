/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:50:45 by lcompieg          #+#    #+#             */
/*   Updated: 2023/01/13 16:05:56 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static int	check_set(char c, char const *set)
{	
	int	index;

	index = 0;
	while (set[index])
	{
		if (c == set[index])
			return (1);
		index++;
	}
	return (0);
}

static int	get_borne(char const *s1, char const *set, int sw)
{
	int	begin;
	int	end;

	begin = 0;
	end = ft_strlen(s1) - 1;
	if (sw == 0)
	{
		while (check_set(s1[begin], set))
			begin++;
		return (begin);
	}
	else
	{
		while (check_set(s1[end], set) && end > 0)
			end--;
		return (end);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		begin;
	int		index;
	int		end;
	char	*str;

	if (s1 == NULL)
		return (NULL);
	begin = get_borne(s1, set, 0);
	end = get_borne(s1, set, 1);
	index = 0;
	if (end > begin)
		str = malloc(sizeof(char) * (end - begin + 2));
	else
		str = malloc(1);
	if (!str)
		return (NULL);
	while (begin < end + 1)
	{
		str[index] = s1[begin];
		index++;
		begin++;
	}
	str[index] = '\0';
	return (str);
}
