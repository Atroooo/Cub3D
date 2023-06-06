/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:17:15 by gclement          #+#    #+#             */
/*   Updated: 2023/06/06 13:30:22 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_column(float distance, t_env *env, float *cam_x)
{
	float	i;

	i = 0;
	while (i < 10)
	{
		i += 1;
		*cam_x += 1;
		draw_wall(distance, env, cam_x);
	}
}

static float	fix_fisheye(float distance, t_env *env)
{
	float	adjust_angle;

	adjust_angle = env->data.angle - env->data.p_angle;
	if (adjust_angle > 2 * M_PI)
		adjust_angle -= 2 * M_PI;
	if (adjust_angle < 0)
		adjust_angle += 2 * M_PI;
	distance = distance * cos(adjust_angle);
	return (distance);
}

/*
	WIN_H / D_ecran = WALL_H / distance
	Hauteur percues(Hp) = D_ecran * WALL_H / distance
	Pixel intervalle mur = Hauteur_regard - Hp / 2
*/
static void	draw_ceiling(float height, t_env *env, float x, float *y)
{
	while (*y < height)
	{
		my_mlx_pixel_put(&env->img, x, *y, 0x42d4f5);
		*y += 1;
	}
}

void	draw_wall(float distance, t_env *env, float *x)
{
	float	height;
	float	y;

	y = 0;
	if (distance < 0.20)
		distance = 0.20;
	distance = fix_fisheye(distance, env);
	height = WALL_H / distance;
	draw_ceiling(E_H - height / 2, env, *x, &y);
	while (y < E_H + height / 2)
	{
		my_mlx_pixel_put(&env->img, *x, y, 0x757575);
		y++;
	}
	while (y < WIN_HEIGHT)
	{
		my_mlx_pixel_put(&env->img, *x, y, 0x572f02);
		y++;
	}
}
