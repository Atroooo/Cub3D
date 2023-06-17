/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:17:15 by gclement          #+#    #+#             */
/*   Updated: 2023/06/17 17:03:12 by gclement         ###   ########.fr       */
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

static char	*choose_pixel_textures(t_ray ray, int y, float height, t_data data)
{
	char			*dst;
	float			t_x;

	//printf("collision.x = %f\n", ray.collision.x);
	t_x = ray.collision.x * 256;
	//printf("t_x = %f\n", t_x);
	if (E_H - height / 2 < 0)
		y = y - (E_H - height / 2);
	y = y * (256 / height);
	if (ray.side == NORTH)
		dst = get_pixel_in_texture(data.textures_img[0], t_x, y);
	else if (ray.side == EAST)
		dst = get_pixel_in_texture(data.textures_img[1], t_x, y);
	else if (ray.side == SOUTH)
		dst = get_pixel_in_texture(data.textures_img[2], t_x, y);
	else
		dst = get_pixel_in_texture(data.textures_img[3], t_x, y);
	return (dst);
}

//N x 0 -> 250 | y 100 -> 103
//S x 0 -> 250 | y 159 -> 162
//W x 197 -> 200 | y 0 -> 250
//E x 208 -> 210 | y 0 -> 250

void	draw_wall(t_ray ray, t_env *env, float x)
{
	float	height;
	float	y;
	char	*dst;
	int		textures_y;

	y = 0;
	textures_y = 0;
	if (ray.length < 0.20)
		ray.length = 0.20;
	(void) choose_pixel_textures;
	ray.length = fix_fisheye(ray.length, env);
	height = D_E * (WALL_H / ray.length);
	draw_ceiling(E_H - height / 2, env, x, &y);
	while (y < E_H + height / 2)
	{
		dst = choose_pixel_textures(ray, textures_y, height, env->data);
		my_mlx_pixel_put(&env->img, x, y, *(unsigned int *)dst);
		y++;
		textures_y++;
	}
	while (y < WIN_HEIGHT)
	{
		my_mlx_pixel_put(&env->img, x, y, env->data.floor_hexa);
		y++;
	}
}
