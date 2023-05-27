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

#include "../../includes/cub3D.h"

/*Check si les textures existent*/
static void	get_north_texture(char *line, t_map_info *map_info)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split[1])
	{
		printf("Error malloc. a\n");
		exit(0);
	}
	map_info->NO_texture = ft_strdup(split[1]);
}

static void	get_south_texture(char *line, t_map_info *map_info)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split[1])
	{
		printf("Error malloc. b\n");
		exit(0);
	}
	map_info->SO_texture = ft_strdup(split[1]);
}

static void	get_west_texture(char *line, t_map_info *map_info)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split[1])
	{
		printf("Error malloc. c\n");
		exit(0);
	}
	map_info->WE_texture = ft_strdup(split[1]);
}

static void	get_east_texture(char *line, t_map_info *map_info)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split[1])
	{
		printf("Error malloc. d\n");
		exit(0);
	}
	map_info->EA_texture = ft_strdup(split[1]);
}

int	get_texture(char *line, t_map_info *map_info)
{
	if (ft_strcompare("NO ", line, 3))
	{
		get_north_texture(line, map_info);
		return (1);
	}
	else if (ft_strcompare("SO ", line, 3))
	{
		get_south_texture(line, map_info);
		return (1);
	}
	else if (ft_strcompare("WE ", line, 3))
	{
		get_west_texture(line, map_info);
		return (1);
	}
	else if (ft_strcompare("EA ", line, 3))
	{
		get_east_texture(line, map_info);
		return (1);
	}
	return (0);
}
