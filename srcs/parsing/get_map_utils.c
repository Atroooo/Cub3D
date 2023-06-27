/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:55:27 by lcompieg          #+#    #+#             */
/*   Updated: 2023/06/27 18:35:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_char_value(t_data *data, int i, int j)
{
	char	**map;

	map = data->map_data.map;
	if (map[i][j] == '0' || map[i][j] == 'N' || \
	map[i][j] == 'S' || map[i][j] == 'E' || \
	map[i][j] == 'W' || map[i][j] == 'O' || \
	map[i][j] == 'D')
		return (1);
	return (0);
}

int	check_bord_char(t_data *data)
{
	char	**map;
	int		i;
	int		j;

	map = data->map_data.map;
	j = 0;
	if (!map[0] || !map[0][0])
		return (0);
	while (map[0][j])
	{
		if (map[0][j] && check_char_value(data, 0, j))
			return (0);
		j++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][0] && check_char_value(data, i, 0))
			return (0);
		i++;
	}
	return (1);
}

static int	check_char(char c)
{
	if (c == '0' || c == '1' || c == ' ' || \
		c == 'N' || c == 'S' || c == 'E' || c == 'W' || \
		c == 'O' || c == 'D')
		return (1);
	else
	{
		printf("Error\nInvalid character in map.\n");
		return (0);
	}
	return (0);
}

static int	check_next_char(char **map, int i, int j, t_map_info map_info)
{
	if (map[i][j + 1] == '\0' && (map[i][j] == '0' || map[i][j] == 'N' \
	|| map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W' || \
	map[i][j] == 'D' || map[i][j] == 'O'))
		return (0);
	if (map[map_info.map_height - 1][j] && \
		(map[map_info.map_height - 1][j] == '0' || \
		map[map_info.map_height - 1][j] == 'N' || \
		map[map_info.map_height - 1][j] == 'E' || \
		map[map_info.map_height - 1][j] == 'W' || \
		map[map_info.map_height - 1][j] == 'S' || \
		map[map_info.map_height - 1][j] == 'D' || \
		map[map_info.map_height - 1][j] == 'O'))
		return (0);
	if ((map[i][j - 1] && map[i][j - 1] == ' ') || \
		(map[i][j + 1] && map[i][j + 1] == ' ') || \
		(map[i - 1] && map[i - 1][j] == ' ') || \
		(map[i + 1] && map[i + 1][j] == ' '))
		return (0);
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
			if (!check_char(map[i][j]))
				free_parsing(data);
			if (map[i][j] && (map[i][j] == '0' || map[i][j] == 'N' \
			|| map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W' || \
			map[i][j] == 'D' || map[i][j] == 'O'))
			{
				if (map[i][j] && !check_next_char(map, i, j, data->map_data))
				{
					printf("Error\nMap is not closed.\n");
					free_parsing(data);
				}
			}
		}
	}
}
