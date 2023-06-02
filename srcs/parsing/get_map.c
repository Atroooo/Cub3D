/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 23:55:09 by marvin            #+#    #+#             */
/*   Updated: 2023/05/27 23:55:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_map(char *line, t_data *data)
{
	char	*tmp_map;

	if (data->map_data.base_map != NULL)
		tmp_map = ft_strdup(data->map_data.base_map);
	else
		tmp_map = ft_strdup("");
	if (data->map_data.base_map != NULL)
		free(data->map_data.base_map);
	data->map_data.base_map = ft_strjoin(tmp_map, line);
	free(tmp_map);
	return (1);
}

static void	get_player_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map_data.map[i])
	{
		j = 0;
		while (data->map_data.map[i][j])
		{
			if (data->map_data.map[i][j] == 'N' || \
				data->map_data.map[i][j] == 'S' || \
				data->map_data.map[i][j] == 'E' || \
				data->map_data.map[i][j] == 'W')
			{
				data->p_pos_x = j;
				data->p_pos_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
	printf("Error\nNo player position.\n");
	free_parsing(data);
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
	data->map_data.map_height = i;
}

void	setup_map(t_data *data)
{
	if (data->map_data.base_map == NULL)
	{
		printf("Error\nNo map.\n");
		free_parsing(data);
	}
	data->map_data.map = ft_split(data->map_data.base_map, '\n');
	if (data->map_data.map == NULL)
	{
		printf("Error malloc.\n");
		free_parsing(data);
	}
	get_size_map(data);
	check_map(data);
	get_player_position(data);
}
