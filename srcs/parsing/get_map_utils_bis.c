/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils_bis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:49:41 by lcompieg          #+#    #+#             */
/*   Updated: 2023/06/27 01:06:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_start(t_data *data)
{
	int	i;

	i = 0;
	while (data->map_data.base_map[i] && data->map_data.base_map[i] != '1')
		i++;
	return (i);
}

int	get_end(t_data *data)
{
	int	i;

	i = ft_strlen(data->map_data.base_map) - 1;
	if (i <= 0)
		return (0);
	while (data->map_data.base_map[i] && data->map_data.base_map[i] != '1')
		i--;
	return (i);
}

static int	check_last_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1')
			return (1);
		else if (line[i] != ' ' && line[i] != '\n')
			return (0);
		i++;
	}
	return (0);
}

void	get_size_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->map_data.map_width = 0;
	while (data->map_data.map[i])
	{
		j = 0;
		while (data->map_data.map[i][j])
			j++;
		if (j > data->map_data.map_width)
			data->map_data.map_width = j;
		i++;
	}
	while (i > 0)
	{
		if (check_last_line(data->map_data.map[i]))
		{
			i += 1;
			break ;
		}
		i--;
	}
	data->map_data.map_height = i;
}
