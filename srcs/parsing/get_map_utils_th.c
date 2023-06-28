/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils_th.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:13:23 by lcompieg          #+#    #+#             */
/*   Updated: 2023/06/28 14:15:33 by lcompieg         ###   ########.fr       */
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

static int	check_last_line(t_data *data)
{
	char	**map;
	int		j;

	j = 0;
	map = data->map_data.map;
	while (map[data->map_data.map_height - 1][j])
	{
		if (map[data->map_data.map_height - 1][j] && \
		(map[data->map_data.map_height - 1][j] == '0' || \
		map[data->map_data.map_height - 1][j] == 'N' || \
		map[data->map_data.map_height - 1][j] == 'E' || \
		map[data->map_data.map_height - 1][j] == 'W' || \
		map[data->map_data.map_height - 1][j] == 'S' || \
		map[data->map_data.map_height - 1][j] == 'D' || \
		map[data->map_data.map_height - 1][j] == 'O'))
			return (0);
		j++;
	}
	return (1);
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
	if (!check_last_line(data))
		return (0);
	return (1);
}
