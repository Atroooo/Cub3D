/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:55:27 by lcompieg          #+#    #+#             */
/*   Updated: 2023/06/01 13:33:32 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_char(char c)
{
	if (c == '0' || c == '1' || c == ' ' || \
		c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	else
	{
		printf("Error\nInvalid character in map.\n");
		return (0);
	}
	return (0);
}

static int	check_next_char(char **map, int i, int j, t_map_info *map_info)
{
	if (map[0][j] && map[0][j] == '0')
		return (0);
	if (map[i][0] && map[i][0] == '0')
		return (0);
	if (map[i][j] == '0' && map[i][j + 1] == '\0')
		return (0);
	if (map[map_info->map_height - 1][j] && \
		map[map_info->map_height - 1][j] == '0')
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

	map = data->map_data->map;
	i = -1;
	while (data->map_data->map[++i])
	{
		j = -1;
		while (data->map_data->map[i][++j])
		{
			if (!check_char(map[i][j]))
				free_parsing(data);
			if (map[i][j] && map[i][j] == '0')
			{
				if (!check_next_char(map, i, j, data->map_data))
				{
					printf("Error\nMap is not closed.\n");
					free_parsing(data);
				}
			}
		}
	}
}
