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

#include "../../includes/cub3D.h"

int	get_resolution(char *line, t_map_info *map_info)
{
	char	**split;

	if (ft_strncmp("R ", line, 2) != 0)
		return (0);
	split = ft_split(line, ' ');
	map_info->res_X = ft_atoi(split[1]);
	map_info->res_Y = ft_atoi(split[2]);
	if (map_info->res_X < 0 || map_info->res_Y < 0)
	{
		printf("Error.\n");
		exit(0);
	}
	return (1);
}
