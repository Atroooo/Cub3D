/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:17:15 by gclement          #+#    #+#             */
/*   Updated: 2023/06/09 16:22:33 by marvin           ###   ########.fr       */
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

static char	*print_pixel_textures(int texture_y, float height, t_data data)
{
	char			*dst;
	float			t_x;
	float			t_y;

	t_x = fmodf(data.wall_x, 19.85) * 25 / 2;
	t_y = fmodf(data.wall_y, 19.85) * 25 / 2;
	// printf("t_x = %f && t_y = %f\n", t_x, t_y);
	if (t_x > t_y)
		dst = get_pixel_in_texture(data.textures_img[0], t_x, texture_y * (256 / height));
	else
		dst = get_pixel_in_texture(data.textures_img[1], t_y, texture_y * (256 / height));
	//printf("test = %f\n", test);
	//t_y = t_y * (height * 256) / 2;
	//printf("t_x = %f && t_y = %f\n", t_x, t_y);
	return (dst);
}
//N x 0 -> 250 | y 100 -> 103
//S x 0 -> 250 | y 159 -> 162
//W x 197 -> 200 | y 0 -> 250
//E x 208 -> 210 | y 0 -> 250
void	draw_wall(float distance, t_env *env, float x)
{
	float	height;
	float	y;
	char	*dst;
	int		textures_y;

	y = 0;
	textures_y = 0;
	if (distance < 0.20)
		distance = 0.20;
	distance = fix_fisheye(distance, env);
	height = D_E * (WALL_H / distance);
	draw_ceiling(E_H - height / 2, env, x, &y);
	while (y < E_H + height / 2)
	{
		dst = print_pixel_textures(textures_y, height, env->data);
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
