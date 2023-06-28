/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 00:09:10 by marvin            #+#    #+#             */
/*   Updated: 2023/05/28 00:09:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_strcompare(char *str1, char *str2, int n)
{
	int	i;

	i = 0;
	if (!str1 || !str2)
		return (0);
	while (str1[i] && str2[i] && i < n)
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

char	*setup_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (NULL);
	while (line[i] && line[i] == ' ')
		i++;
	return (&line[i]);
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

void	set_variables(t_data *data, int i, int j)
{
	data->p_pos_x = j;
	data->p_pos_y = i;
	data->p_angle = get_angle(data->map_data.map[i][j]);
	data->p_delta.x = cos(data->p_angle);
	data->p_delta.y = sin(data->p_angle);
}

void	verif_param(t_data *data)
{
	if (data->no == NULL || data->so == NULL || data->we == NULL || \
		data->ea == NULL)
	{
		printf("Error\nMissing texture ?\n");
		free_parsing(data);
	}
	if (data->floor_color == NULL || data->ceiling_color == NULL)
	{
		printf("Error\nMissing color ?\n");
		free_parsing(data);
	}
}
