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
	if (!tmp_map)
	{
		printf("Error malloc.\n");
		free(line);
		free_parsing(data);
	}
	if (data->map_data.base_map != NULL)
		free(data->map_data.base_map);
	data->map_data.base_map = ft_strjoin(tmp_map, line);
	if (!data->map_data.base_map)
	{
		printf("Error malloc.\n");
		free(line);
		free(tmp_map);
		free_parsing(data);
	}
	free(tmp_map);
	return (1);
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

	i = -1;
	while (data->map_data.map[++i])
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
				set_variables(data, i, j);
			j++;
		}
	}
	if (data->p_pos_x == 0 && data->p_pos_y == 0)
	{
		printf("Error\nNo player position.\n");
		free_parsing(data);
	}
}

static void	check_if_line_empty(t_data *data, int s, int e)
{
	int	verif;

	verif = 0;
	while (s < e && data->map_data.base_map[s])
	{
		while (s < e && data->map_data.base_map[s] \
			&& data->map_data.base_map[s] != '\n')
		{
			if (data->map_data.base_map[s] == '0' \
				|| data->map_data.base_map[s] == '1')
				verif++;
			s++;
		}
		if (verif != 0 && data->map_data.base_map[s] == '\0')
			break ;
		if (verif == 0)
		{
			printf("Error\nEmpty line in map.\n");
			free_parsing(data);
		}
		verif = 0;
		s++;
	}
}

void	setup_map(t_data *data)
{
	if (data->map_data.base_map == NULL)
	{
		printf("Error\nNo map.\n");
		free_parsing(data);
	}
	check_if_line_empty(data, get_start(data), get_end(data));
	data->map_data.map = ft_split(data->map_data.base_map, '\n');
	if (data->map_data.map == NULL)
	{
		printf("Error malloc.\n");
		free_parsing(data);
	}
	get_size_map(data);
	if (data->map_data.map_height == 1)
	{
		printf("Error\nMap too small.\n");
		free_parsing(data);
	}
	check_map(data);
	get_player_position(data);
}
