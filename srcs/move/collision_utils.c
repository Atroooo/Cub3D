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

int	check_cond_angle_no(t_data *data)
{
	return ((data->p_angle > 5.7f && data->p_angle < M_PI * 2) || \
			(data->p_angle > 0.0f && data->p_angle < M_PI * 1.5f));
}

int	check_cond_angle_so(t_data *data)
{
	if ((data->p_angle > 5.7f && data->p_angle <= 6.22f) || \
		(data->p_angle > 2.56f && data->p_angle < 4.78f))
	{
		printf("cond 1\n");
		return (0);
	}
	if (data->p_angle > 0.0f && data->p_angle < 1.5f)
	{
		printf("cond 2\n");
		return (1);
	}
	if ((data->p_angle >= 4.8f && data->p_angle < 5.7f) || \
		(data->p_angle > 3.1f && data->p_angle < 3.42f))
	{
		printf("cond 3\n");
		return (2);
	}
	return (-1);
}

int	check_cond_angle(int s, t_data *data)
{
	if (s == 3)
		return ((data->p_angle > 4.5f && data->p_angle < M_PI * 2) || \
			(data->p_angle > 0.0f && data->p_angle < M_PI));
	if (s == 4)
		return ((data->p_angle > 5.7f && data->p_angle < M_PI * 2) || \
			(data->p_angle > 0.0f && data->p_angle < M_PI));
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
