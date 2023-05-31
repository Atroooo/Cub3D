/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:59:41 by marvin            #+#    #+#             */
/*   Updated: 2023/05/27 22:59:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_resolution(char *line, t_data *map_info)
{
	char	**split;

	if (ft_strncmp("R ", line, 2) != 0)
		return (0);
	split = ft_split(line, ' ');
	if (!split || !split[1] || !split[2])
	{
		printf("Error.\n");
		free_char_array(split);
		free(line);
		free_parsing(map_info);
	}
	map_info->res_x = ft_atoi(split[1]);
	map_info->res_y = ft_atoi(split[2]);
	free_char_array(split);
	if (map_info->res_x < 0 || map_info->res_y < 0)
	{
		printf("Error.\n");
		free(line);
		free_parsing(map_info);
	}
	return (1);
}
