/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:35:38 by gclement          #+#    #+#             */
/*   Updated: 2023/06/03 11:34:41 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_line(t_env *env, float dy, float dx, float	*distance)
{
	int		y;
	int		x;
	float	pix_x;
	float	pix_y;
	char	**map;

	map = env->data.map_data.map;
	y = (env->data.p_pos_y) / TILE_SIZE;
	x = (env->data.p_pos_x) / TILE_SIZE;
	pix_x = env->data.p_pos_x + 5;
	pix_y = env->data.p_pos_y + 5;
	while (map[y][x] != '1')
	{
		my_mlx_pixel_put(&env->img, pix_x, pix_y, 0x41801f);
		*distance += 1;
		pix_y += dy / 5;
		pix_x += dx / 5;
		y = pix_y / TILE_SIZE;
		x = pix_x / TILE_SIZE;
	}
}

void	raycasting(t_env *env)
{
	float	angle;
	float	end_angle;
	float	dy;
	float	dx;
	float	distance;

	distance = 0;
	end_angle = env->data.p_angle + M_PI / 6;
	angle = env->data.p_angle;
	while (angle <= end_angle)
	{
		angle += 0.01;
		dx = cos(angle) * 5;
		dy = sin(angle) * 5;
		draw_line(env, dy, dx, &distance);
	}
	end_angle = env->data.p_angle + 2 * M_PI;
	angle = env->data.p_angle + (11 * M_PI) / 6;
	while (angle <= end_angle)
	{
		angle += 0.01;
		dx = cos(angle) * 5;
		dy = sin(angle) * 5;
		draw_line(env, dy, dx, &distance);
	}
}

//  gauche = angle + M_PI / 6;
//  droite = angle + 11 * M_PI / 6);
// 0.623599; fov_max = 5.859587
//fov_max = env->data.p_angle + 11 * M_PI / 6;