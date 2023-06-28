/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:55:27 by lcompieg          #+#    #+#             */
/*   Updated: 2023/06/28 14:13:50 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

static int	check_next_char(char **map, int i, int j)
{
	if (map[i][j + 1] == '\0' && (map[i][j] == '0' || map[i][j] == 'N' \
	|| map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W' || \
	map[i][j] == 'D' || map[i][j] == 'O'))
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
				if (map[i][j] && !check_next_char(map, i, j))
				{
					printf("Error\nMap is not closed.\n");
					free_parsing(data);
				}
			}
		}
	}
}
