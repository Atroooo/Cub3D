/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:17:15 by gclement          #+#    #+#             */
/*   Updated: 2023/06/21 09:35:00 by gclement         ###   ########.fr       */
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

static unsigned int	choose_pixel_textures(t_ray ray, int y, float height, t_data data)
{
	char			*dst;
	int				t_x;

	t_x = (ray.collision.x - (int) ray.collision.x) * 256;
	if (E_H - height / 2 < 0)
		y = y - (E_H - height / 2);
	y = y * (256 / height);
	if (t_x < 0 && y == 0)
		y++;
	if (ray.side == NORTH)
		dst = get_pixel_in_texture(data.textures_img[0], t_x, y);
	else if (ray.side == EAST)
		dst = get_pixel_in_texture(data.textures_img[1], t_x, y);
	else if (ray.side == SOUTH)
		dst = get_pixel_in_texture(data.textures_img[2], t_x, y);
	else
		dst = get_pixel_in_texture(data.textures_img[3], t_x, y);
	return (*(unsigned int *)dst);
}

static unsigned int	pixel_brightness(float distance, unsigned int color)
{
	if (distance > 7)
	{
		color = color / 2;
	}
	return (color);
}

void	draw_wall(t_ray ray, t_env *env, float x)
{
	float			height;
	float			y;
	unsigned int	dst;
	int				textures_y;

	y = 0;
	(void) pixel_brightness;
	textures_y = 0;
	if (ray.length < 0.20)
		ray.length = 0.20;
	ray.length = fix_fisheye(ray.length, env);
	height = D_E * (WALL_H / ray.length);
	draw_ceiling(E_H - height / 2, env, x, &y);
	while (y < E_H + height / 2)
	{
		dst = choose_pixel_textures(ray, textures_y, height, env->data);
		//dst = pixel_brightness(ray.length, dst);
		my_mlx_pixel_put(&env->img, x, y, dst);
		y++;
		textures_y++;
	}
	while (y < WIN_HEIGHT)
	{
		my_mlx_pixel_put(&env->img, x, y, env->data.floor_hexa);
		y++;
	}
}
