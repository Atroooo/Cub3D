/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:17:15 by gclement          #+#    #+#             */
/*   Updated: 2023/06/15 14:42:39 by lcompieg         ###   ########.fr       */
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

static int	choose_textures(t_data data, char **map)
{
	int	x;
	int	y;

	y = data.wall_y / TILE_SIZE;
	x = data.wall_x / TILE_SIZE;
	if ((int)((data.wall_y + 0.5) / TILE_SIZE) != y && map[(int)((data.wall_y + 0.5) / TILE_SIZE)][x] != '1')
		return (0);
	if ((int)((data.wall_y - 0.5) / TILE_SIZE) != y && map[(int)((data.wall_y - 0.5) / TILE_SIZE)][x] != '1')
		return (2);
	if ((int)((data.wall_x - 0.5) / TILE_SIZE) != x)
		return (1);
	if ((int)((data.wall_x + 0.5) / TILE_SIZE) != x)
		return (3);
	return (3);
}

static char	*choose_pixel_textures(int y, float height, t_data data)
{
	char			*dst;
	float			t_x;
	float			t_y;
	int				i;

	t_x = fmodf(data.wall_x, 19.85) * 25 / 2;
	t_y = fmodf(data.wall_y, 19.85) * 25 / 2;
	if (E_H - height / 2 < 0)
		y = y - (E_H - height / 2);
	y = y * (256 / height);
	i = choose_textures(data, data.map_data.map);
	if (i == 0)
		dst = get_pixel_in_texture(data.textures_img[i], t_x, y);
	else if (i == 2)
		dst = get_pixel_in_texture(data.textures_img[i], 50 - t_x, y);
	else if (i == 3)
		dst = get_pixel_in_texture(data.textures_img[i], t_y, y);
	else
		dst = get_pixel_in_texture(data.textures_img[i], t_y, y);
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
		dst = choose_pixel_textures(textures_y, height, env->data);
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
