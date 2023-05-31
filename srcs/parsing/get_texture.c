/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 23:02:37 by marvin            #+#    #+#             */
/*   Updated: 2023/05/27 23:02:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	get_north_texture(char *line, t_data *data)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split[1])
	{
		printf("Error\n Missing texture ?\n");
		free_parsing(data);
	}
	data->no = ft_strdup(split[1]);
	free_char_array(split);
}

static void	get_south_texture(char *line, t_data *data)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split[1])
	{
		printf("Error\n Missing texture ?\n");
		free_parsing(data);
	}
	data->so = ft_strdup(split[1]);
	free_char_array(split);
}

static void	get_west_texture(char *line, t_data *data)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split[1])
	{
		printf("Error\n Missing texture ?\n");
		free_parsing(data);
	}
	data->we = ft_strdup(split[1]);
	free_char_array(split);
}

static void	get_east_texture(char *line, t_data *data)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split[1])
	{
		printf("Error\n Missing texture ?\n");
		free_parsing(data);
	}
	data->ea = ft_strdup(split[1]);
	free_char_array(split);
}

int	get_texture(char *line, t_data *data)
{
	if (ft_strcompare("NO ", line, 3))
	{
		get_north_texture(line, data);
		return (1);
	}
	else if (ft_strcompare("SO ", line, 3))
	{
		get_south_texture(line, data);
		return (1);
	}
	else if (ft_strcompare("WE ", line, 3))
	{
		get_west_texture(line, data);
		return (1);
	}
	else if (ft_strcompare("EA ", line, 3))
	{
		get_east_texture(line, data);
		return (1);
	}
	return (0);
}
