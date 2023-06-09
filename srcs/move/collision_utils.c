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

int	check_cond_angle(int s, t_data *data)
{
	if (s == 1)
		return ((data->p_angle > 5.70 && data->p_angle < M_PI * 2) || \
			(data->p_angle > 0.0 && data->p_angle < M_PI * 1.5));
	if (s == 2)
		return ((data->p_angle < 5.0 && data->p_angle > M_PI * 1.5) || \
			(data->p_angle < 5.70 && data->p_angle > M_PI * 2) || \
			(data->p_angle > 0.0 && data->p_angle < 1.5));
	if (s == 3)
		return ((data->p_angle > 4.50 && data->p_angle < M_PI * 2) || \
			(data->p_angle > 0.0 && data->p_angle < M_PI));
	if (s == 4)
		return ((data->p_angle > 5.70 && data->p_angle < M_PI * 2) || \
			(data->p_angle > 0.0 && data->p_angle < M_PI));
	return (0);
}

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
		x += (x - data->p_pos_x);
		y += (y - data->p_pos_y);
		x_t = x / TILE_SIZE;
		y_t = y / TILE_SIZE;
		dist += 0.5;
	}
	return (dist);
}
