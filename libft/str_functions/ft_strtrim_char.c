/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:43:24 by marvin            #+#    #+#             */
/*   Updated: 2023/06/06 18:43:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static int	check_set(char c, char set)
{	
	if (c == set)
		return (1);
	return (0);
}

static int	get_borne(char const *s1, char set, int sw)
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

char	*ft_strtrim_char(char const *s1, char set)
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