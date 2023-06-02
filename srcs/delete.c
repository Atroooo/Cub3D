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

void	print_param(t_data *data)
{
	int	i;

	printf("NO : %s\n", data->no);
	printf("SO : %s\n", data->so);
	printf("WE : %s\n", data->we);
	printf("EA : %s\n", data->ea);
	printf("Color floor : %d %d %d\n", data->floor_color[0], \
		data->floor_color[1], data->floor_color[2]);
	printf("Color ceiling : %d %d %d\n", data->ceiling_color[0], \
		data->ceiling_color[1], data->ceiling_color[2]);
	printf("player pos : %d %d\n", data->p_pos_x,
		data->p_pos_y);
	// printf("base map : %s\n", data->map_data.base_map);
	i = 0;
	while (data->map_data.map[i])
	{
		printf("map line %d : %s\n", i, data->map_data.map[i]);
		i++;
	}
	printf("map_width = %d\n map_height = %d\n", data->map_data.map_width, data->map_data.map_height);
}
