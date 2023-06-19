/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:35:38 by gclement          #+#    #+#             */
/*   Updated: 2023/06/19 14:58:36 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//x + 1, y - 1
// float	calc_radius(t_env *env, float dy, float dx)
// {
// 	int		y;
// 	int		x;
// 	float	pix_x;
// 	float	pix_y;
// 	float	distance;

// 	y = (env->data.p_pos_y) / TILE_SIZE;
// 	x = (env->data.p_pos_x) / TILE_SIZE;
// 	pix_x = env->data.p_pos_x + 5.0;
// 	pix_y = env->data.p_pos_y + 5.0;
// 	distance = 0;
// 	while (env->data.map_data.map[y][x] != '1')
// 	{
// 		my_mlx_pixel_put(&env->img, pix_x, pix_y, 0x41801f);
// 		pix_y += dy / 25.0;
// 		pix_x += dx / 25.0;
// 		distance += 0.01;
// 		y = pix_y / TILE_SIZE;
// 		x = pix_x / TILE_SIZE;
// 		if (!check_wall_angle(x, y, env->data, env->data.map_data.map))
// 			break ;
// 	}
// 	env->data.wall_x = pix_x;
// 	env->data.wall_y = pix_y;
// 	return (distance);
// }

void	raycasting(t_env *env)
{
	float		angle;
	t_vector_2f	dir;
	float		x;
	t_ray		ray;

	(void) ray;
	angle = env->data.p_angle - 20.0 * RAD;
	x = 0;
	while (x / 100 < WIN_WIDTH / 100)
	{
		dir.x = cos(angle);
		dir.y = sin(angle);
		ray = dda(dir.x, dir.y, env);
		draw_wall(ray, env, x);
		// calc_radius(env, dy, dx);
		angle += (RAD * (40.00 / WIN_WIDTH));
		env->data.angle = angle;
		x++;
	}
	mlx_put_image_to_window(env->windows.mlx, env->windows.win, \
		env->img.img, 0, 0);
}

// longueur mur = 20;
// largeur mur = 20;

//pix_x = 159.951569, pix_y = 19.927576, x = 7, y = 0
//pix_x = 140.002823, pix_y = 19.897259, x = 7, y = 0

// pix_x = 180.015488, pix_y = 99.999672, x = 9, y = 4
// pix_x = 180.002579, pix_y = 80.155655, x = 9, y = 4

// pix_x = 60.018707, pix_y = 59.967529, x = 3, y = 2
// pix_x = 79.997200, pix_y = 59.847008, x = 3, y = 2

// 19.978493

// 19.844017