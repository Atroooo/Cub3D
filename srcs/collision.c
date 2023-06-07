/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:40:23 by gclement          #+#    #+#             */
/*   Updated: 2023/06/07 17:37:37 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>
#define HITBOX 0.5

static float	calc_seg_n(t_data *data, float x, float y)
{
	float	dist;
	int		dx;
	int		dy;

	dx = x / TILE_SIZE;
	dy = y / TILE_SIZE;
	while (data->map_data.map[dy][dx] && data->map_data.map[dy][dx] != '1')
	{
		dx = (dx * TILE_SIZE + data->p_delta_x) / TILE_SIZE;
		dy = (dy * TILE_SIZE + data->p_delta_y) / TILE_SIZE;
	}
	dist = sqrt(pow((dx - x), 2) + pow((dy - y), 2));
	printf("N dist = %f\n", dist);
	return (dist);
}

static float	calc_seg_s(t_data *data, float x, float y)
{
	float	dist;
	int		dx;
	int		dy;

	dx = x / TILE_SIZE;
	dy = y / TILE_SIZE;
	while (data->map_data.map[dy][dx] && data->map_data.map[dy][dx] != '1')
	{
		dx = (dx * TILE_SIZE - data->p_delta_x) / TILE_SIZE;
		dy = (dy * TILE_SIZE - data->p_delta_y) / TILE_SIZE;
	}
	dist = sqrt(pow((dx - x), 2) + pow((dy - y), 2));
	printf("S dist = %f\n", dist);
	return (dist);
}

static float	calc_seg_w(t_data *data, float x, float y)
{
	float	dist;
	int		dx;
	int		dy;

	dx = x / TILE_SIZE;
	dy = y / TILE_SIZE;
	while (data->map_data.map[dy][dx] && data->map_data.map[dy][dx] != '1')
	{
		dx = (dx * TILE_SIZE - cos(data->p_angle + M_PI / 2)) / TILE_SIZE;
		dy = (dy * TILE_SIZE - sin(data->p_angle + M_PI / 2)) / TILE_SIZE;
	}
	dist = sqrt(pow((dx - x), 2) + pow((dy - y), 2));
	printf("W dist = %f\n", dist);
	return (dist);
}

static float	calc_seg_e(t_data *data, float x, float y)
{
	float	dist;
	int		dx;
	int		dy;

	dx = x / TILE_SIZE;
	dy = y / TILE_SIZE;
	while (data->map_data.map[dy][dx] && data->map_data.map[dy][dx] != '1')
	{
		dx = (dx * TILE_SIZE + cos(data->p_angle + M_PI / 2)) / TILE_SIZE;
		dy = (dy * TILE_SIZE + sin(data->p_angle + M_PI / 2)) / TILE_SIZE;
	}
	dist = sqrt(pow((dx - x), 2) + pow((dy - y), 2));
	printf("E dist = %f\n", dist);
	return (dist);
}

int	collision(int pos_x, int pos_y, t_data *data, char c)
{
	if (c == 'N')
		if (calc_seg_n(data, pos_x, pos_y) < HITBOX)
			return (0);
	if (c == 'S')
		if (calc_seg_s(data, pos_x, pos_y) < HITBOX)
			return (0);
	if (c == 'E')
		if (calc_seg_e(data, pos_x, pos_y) < HITBOX)
			return (0);
	if (c == 'W')
		if (calc_seg_w(data, pos_x, pos_y) < HITBOX)
			return (0);
	return (1);
}
