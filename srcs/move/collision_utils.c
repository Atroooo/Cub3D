/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:53:03 by marvin            #+#    #+#             */
/*   Updated: 2023/06/09 14:53:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

float	distance_wall(float x, float y, t_data *data)
{
	float	dist;
	int		x_t;
	int		y_t;

	dist = 0.0;
	x_t = x / TILE_SIZE;
	y_t = y / TILE_SIZE;
	while (y_t >= 0 && y_t < data->map_data.map_height && \
	data->map_data.map[y_t][x_t] && data->map_data.map[y_t][x_t] != '1')
	{
		x += (x - data->p_pos_x) / 10.0;
		y += (y - data->p_pos_y) / 10.0;
		// printf("x = %f, y = %f\n", x, y);
		x_t = x / TILE_SIZE;
		y_t = y / TILE_SIZE;
	// 	if (y_t >= 0 && y_t < data->map_data.map_height && 
	// data->map_data.map[y_t][x_t])
	// 		printf("x_t = %d, y_t = %d, |%c|\n", x_t, y_t, data->map_data.map[y_t][x_t]);
		dist += 0.1;
	}
	return (dist);
}
