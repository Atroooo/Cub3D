/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:40:23 by gclement          #+#    #+#             */
/*   Updated: 2023/06/07 22:03:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static float	distance_wall(float x, float y, t_data *data)
{
	float	dist;
	int		x_t;
	int		y_t;
	
	dist = 0.0;
	x_t = x / TILE_SIZE;
	y_t = y / TILE_SIZE;
	while (y_t > 0 && y_t < data->map_data.map_height && \
	data->map_data.map[y_t][x_t] && data->map_data.map[y_t][x_t] != '1')
	{
		x += (x - data->p_pos_x);
		y += (y - data->p_pos_y);
		x_t = x / TILE_SIZE;
		y_t = y / TILE_SIZE;
		dist += 0.1;
	}
	return (dist);
}

int	collision(int x, int y, t_data *data, char c)
{
	(void) x;
	(void) y;
	(void) c;
	// if (c == 'N' || c == 'S')
	// {
		if (distance_wall(data->p_pos_x + data->p_delta_x, \
			data->p_pos_y + data->p_delta_y, data) <= 0.15)
			return (0);
		return (1);
	// }
	// return (1);
}
