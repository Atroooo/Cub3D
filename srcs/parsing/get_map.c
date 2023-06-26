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

static void	check_if_line_empty(t_data *data)
{
	int	i;
	int	verif;

	i = 0;
	while (data->map_data.base_map[i] && data->map_data.base_map[i] != '1')
		i++;
	verif = 0;
	while (data->map_data.base_map[++i])
	{
		while (data->map_data.base_map[i] && data->map_data.base_map[i] != '\n')
		{
			if (data->map_data.base_map[i] == '0' \
				|| data->map_data.base_map[i] == '1')
				verif++;
			i++;
		}
		if (verif != 0 && data->map_data.base_map[i] == '\0')
			break ;
		if (verif == 0)
		{
			printf("Error\nEmpty line in map.\n");
			free_parsing(data);
		}
		verif = 0;
	}
}

void	setup_map(t_data *data)
{
	if (data->map_data.base_map == NULL)
	{
		printf("Error\nNo map.\n");
		free_parsing(data);
	}
	check_if_line_empty(data);
	data->map_data.map = ft_split(data->map_data.base_map, '\n');
	if (data->map_data.map == NULL)
	{
		printf("Error malloc.\n");
		free_parsing(data);
	}
	get_size_map(data);
	if (!check_bord_char(data))
	{
		printf("Error\nMap not closed.\n");
		free_parsing(data);
	}
	check_map(data);
	get_player_position(data);
}
