/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:17:15 by gclement          #+#    #+#             */
/*   Updated: 2023/06/09 10:15:37 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static float	fix_fisheye(float distance, t_env *env)
{
	float	adjust_angle;

	adjust_angle = env->data.angle - env->data.p_angle;
	if (adjust_angle >= 2.0 * M_PI)
		adjust_angle -= 2.0 * M_PI;
	if (adjust_angle <= 0.0)
		adjust_angle = 0.0;
	distance = distance * cos(adjust_angle);
	return (distance);
}

static void	draw_ceiling(float height, t_env *env, float x, float *y)
{
	while (*y < height)
	{
		my_mlx_pixel_put(&env->img, x, *y, env->data.ceiling_hexa);
		*y += 1;
	}
}

char	*get_pixel_in_texture(t_img data, int x, int y)
{
	char	*dst;
	int		bit;

	bit = data.bits_per_pixel / 8;
	dst = data.addr + (y * data.line_length + x * (bit));
	return (dst);
}

static void	print_pixel_textures(float *t_y, float y, float x, float height, t_env *env)
{
	char			*dst;
	int				t_x;

	(void) dst;
	(void) env;
	(void) y;
	(void) height;
	t_x = (int)x % 256;
	*t_y = (int)y % 256;
	dst = get_pixel_in_texture(env->data.textures_img, t_x, *t_y);
	//my_mlx_pixel_put(&env->img, x, y, *(unsigned int *)dst);
}

void	draw_wall(float distance, t_env *env, float x)
{
	float	height;
	float	y;
	float	textures_y;

	y = 0;
	textures_y = 0;
	if (distance < 0.20)
		distance = 0.20;
	distance = fix_fisheye(distance, env);
	height = D_E * (WALL_H / distance);
	draw_ceiling(E_H - height / 2, env, x, &y);
	while (y < E_H + height / 2)
	{
		print_pixel_textures(&textures_y, y, x, height, env);
		y++;
	}
	while (y < WIN_HEIGHT)
	{
		my_mlx_pixel_put(&env->img, x, y, env->data.floor_hexa);
		y++;
	}
}
