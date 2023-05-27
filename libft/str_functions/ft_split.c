/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:44:18 by lcompieg          #+#    #+#             */
/*   Updated: 2023/01/13 16:05:56 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static void	*malloc_error(char **str, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static int	get_malloc_size(char const *s, char c)
{
	int	i;
	int	count;
	int	start;

	if (s == NULL)
		return (0);
	i = 0;
	count = 1;
	start = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (start < i)
			count++;
	}
	return (count);
}

static void	variable_declaration(int *index, int *word_index, int *borne)
{
	*index = -1;
	*word_index = 0;
	*borne = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		index;
	int		word_index;
	int		borne;

	str = malloc(sizeof(char *) * (get_malloc_size(s, c)));
	if (!str || s == NULL)
		return (NULL);
	variable_declaration(&index, &word_index, &borne);
	while (s[++index])
	{
		if (s[index] && s[index] != c)
		{
			borne = index;
			while (s[index + 1] && s[index] != c)
				index++;
			if (s[index + 1] == '\0' && s[index] != c)
				str[word_index++] = ft_substr(s, borne, index - borne + 1);
			else
				str[word_index++] = ft_substr(s, borne, index - borne);
			if (!str && index > borne)
				return (malloc_error(str, word_index));
		}
	}
	return (str[word_index] = NULL, str);
}
