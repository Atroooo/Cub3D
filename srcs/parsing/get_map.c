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

static float	get_angle(char c)
{
	if (c == 'E')
		return (M_PI * 2);
	else if (c == 'W')
		return (M_PI);
	else if (c == 'S')
		return (M_PI / 2);
	else if (c == 'N')
		return (3 * M_PI / 2);
	return (0.0);
}

static int	check_check_char(char c)
{
	return (c == 'N' || c == 'S' || \
			c == 'E' || c == 'W');
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
			if ((data->p_pos_x != 0 || data->p_pos_y != 0) && \
				check_check_char(data->map_data.map[i][j]))
			{
				printf("Error\nMultiple player position.\n");
				free_parsing(data);
			}
			if (check_check_char(data->map_data.map[i][j]))
			{
				data->p_pos_x = j;
				data->p_pos_y = i;
				data->p_angle = get_angle(data->map_data.map[i][j]);
				data->p_delta_x = cos(data->p_angle) * 5;
				data->p_delta_y = sin(data->p_angle) * 5;
			}
			j++;
		}
		i++;
	}
	if (data->p_pos_x == 0 && data->p_pos_y == 0)
	{
		printf("Error\nNo player position.\n");
		free_parsing(data);
	}
}

void	setup_map(t_data *data)
{
	check_if_line_empty(data);
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
