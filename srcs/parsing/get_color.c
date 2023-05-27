/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 23:15:44 by marvin            #+#    #+#             */
/*   Updated: 2023/05/27 23:15:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*Gerer s'il manque valeur de couleur*/
static void	get_floor_color(char *line, t_map_info *map_info)
{
	char	**split;
	char	**split2;

	split = ft_split(line, ',');
	map_info->floor_color = malloc(sizeof(int) * 3);
	if (!split || !map_info->floor_color)
	{
		printf("Error malloc.\n");
		exit(0);
	}
	split2 = ft_split(split[0], ' ');
	if (!split2[1])
	{
		printf("Error malloc.\n");
		exit(0);
	}
	map_info->floor_color[0] = ft_atoi(split2[1]);
	map_info->floor_color[1] = ft_atoi(split[1]);
	map_info->floor_color[2] = ft_atoi(split[2]);
	free_char_array(split2);
	free_char_array(split);
}

static void	get_ceiling_color(char *line, t_map_info *map_info)
{
	char	**split;
	char	**split2;

	split = ft_split(line, ',');
	map_info->ceiling_color = malloc(sizeof(int) * 3);
	if (!map_info->ceiling_color || !split)
	{
		printf("Error malloc.\n");
		exit(0);
	}
	split2 = ft_split(split[0], ' ');
	if (!split2[1])
	{
		printf("Error malloc. 2\n");
		exit(0);
	}
	map_info->ceiling_color[0] = ft_atoi(split2[1]);
	map_info->ceiling_color[1] = ft_atoi(split[1]);
	map_info->ceiling_color[2] = ft_atoi(split[2]);
	free_char_array(split2);
	free_char_array(split);
}

int	get_color(char *line, t_map_info *map_info)
{
	if (ft_strcompare("F ", line, 2))
	{
		get_floor_color(line, map_info);
		return (1);
	}
	else if (ft_strcompare("C ", line, 2))
	{
		get_ceiling_color(line, map_info);
		return (1);
	}
	return (0);
}
