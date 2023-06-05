/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:35:38 by gclement          #+#    #+#             */
/*   Updated: 2023/06/05 17:32:11 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//x + 1, y - 1
static	int	check_wall_angle(int x, int y, t_data data, char **map)
{
	int	p_x;
	int	p_y;

	p_y = data.p_pos_y / TILE_SIZE;
	p_x = data.p_pos_x / TILE_SIZE;
	if (p_y > y || p_x < x)
	{
		if (!map[y + 1] || !map[y][x] || !map[y + 1][x] || !map[y][x - 1])
			return (1);
		if (p_y > y && p_x < x && map[y + 1][x] == '1' && map[y][x - 1] == '1')
			return (0);
	}
	else
	{
		if (!map[y][x] || !map[y - 1] || !map[y - 1][x] || !map[y][x + 1])
			return (1);
		if (p_y < y && map[y - 1][x] == '1' && map[y][x + 1] == '1')
			return (0);
	}
	return (1);
}

void	draw_column(float distance, t_img *img, float *cam_x)
{
	float	i;

	i = 0;
	while (i < 10)
	{
		i += 1;
		*cam_x += 1;
		draw_wall(distance, img, cam_x);
	}
}
void	draw_line(t_env *env, float dy, float dx, float	*cam_x)
{
	int		y;
	int		x;
	float	pix_x;
	float	pix_y;
	float	distance;

	y = (env->data.p_pos_y) / TILE_SIZE;
	x = (env->data.p_pos_x) / TILE_SIZE;
	pix_x = env->data.p_pos_x + 5;
	pix_y = env->data.p_pos_y + 5;
	while (env->data.map_data.map[y][x] != '1')
	{
		my_mlx_pixel_put(&env->img, pix_x, pix_y, 0x41801f);
		distance += 0.1;
		pix_y += dy / 5;
		pix_x += dx / 5;
		y = pix_y / TILE_SIZE;
		x = pix_x / TILE_SIZE;
		if (!check_wall_angle(x, y, env->data, env->data.map_data.map))
			break ;
	}
	draw_column(distance, &env->img, cam_x);
}

void	raycasting(t_env *env)
{
	float	angle;
	float	end_angle;
	float	dy;
	float	dx;
	float	distance;

	distance = 0;
	end_angle = env->data.p_angle + 2 * M_PI;
	angle = env->data.p_angle + (11 * M_PI) / 6;
	while (angle <= end_angle)
	{
		angle += 0.01;
		dx = cos(angle) * 5;
		dy = sin(angle) * 5;
		draw_line(env, dy, dx, &distance);
	}
	end_angle = env->data.p_angle + M_PI / 6;
	angle = env->data.p_angle;
	while (angle <= end_angle)
	{
		angle += 0.01;
		dx = cos(angle) * 5;
		dy = sin(angle) * 5;
		draw_line(env, dy, dx, &distance);
	}
}
