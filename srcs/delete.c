/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 23:38:39 by marvin            #+#    #+#             */
/*   Updated: 2023/05/27 23:38:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	print_param(t_map_info *map_info)
{
	printf("R : %d %d\n", map_info->res_X, map_info->res_Y);
	printf("NO : %s\n", map_info->NO_texture);
	printf("SO : %s\n", map_info->SO_texture);
	printf("WE : %s\n", map_info->WE_texture);
	printf("EA : %s\n", map_info->EA_texture);
	printf("Color floor : %d %d %d\n", map_info->floor_color[0], \
		map_info->floor_color[1], map_info->floor_color[2]);
	printf("Color ceiling : %d %d %d\n", map_info->ceiling_color[0], \
		map_info->ceiling_color[1], map_info->ceiling_color[2]);
	// printf("player pos : %d %d\n", map_info->player_pos_X, 
	// 	map_info->player_pos_Y);
}
