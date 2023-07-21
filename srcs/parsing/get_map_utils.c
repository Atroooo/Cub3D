/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:55:27 by lcompieg          #+#    #+#             */
/*   Updated: 2023/07/21 17:10:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_char_allowed(char c)
{
	if (c == '0' || \
		c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	if (c == '1' || c == ' ')
		return (2);
	else
	{
		printf("Error\nInvalid character in map.\n");
		return (0);
	}
	return (0);
}

static int	check_next_char(char **map, int i, int j, t_data *data)
{
	if (check_char_allowed(map[i][j]) == 1)
	{
		if (i == 0 || i == data->map_data.map_height - 1 || \
			j == 0 || (size_t)j == ft_strlen(map[i]))
			return (0);
		if (!map[i - 1][j] || !map[i + 1][j] || \
			!map[i][j - 1] || !map[i][j + 1])
			return (0);
		if ((map[i][j - 1] && (map[i][j - 1] == ' ' || \
			map[i][j - 1] == '\0')) || \
			(map[i][j + 1] && (map[i][j + 1] == ' ' || \
			map[i][j + 1] == '\0')) || \
			(map[i - 1] && (map[i - 1][j] == ' ' || map[i - 1][j] == '\0')) || \
			(map[i + 1] && (map[i + 1][j] == ' ' || map[i + 1][j] == '\0')))
			return (0);
		return (1);
	}
	return (1);
}

void	check_map(t_data *data)
{
	char	**map;
	int		i;
	int		j;

	map = data->map_data.map;
	i = -1;
	while (data->map_data.map[++i])
	{
		j = -1;
		while (data->map_data.map[i][++j])
		{
			if (check_char_allowed(map[i][j]) == 0)
				free_parsing(data);
			if (!check_next_char(map, i, j, data))
			{
				printf("Error\nMap is not closed.\n");
				free_parsing(data);
			}
		}
	}
}
