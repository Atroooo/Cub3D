/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:07:21 by gclement          #+#    #+#             */
/*   Updated: 2023/06/27 14:42:15 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_tile(t_vector_2d pixel, uint32_t color, t_img *img)
{
	int		y_len;
	float	d;
	float	x_inc;
	float	steps;
	int		tmp_x;

	pixel.y *= TILE_SIZE;
	pixel.x *= TILE_SIZE;
	y_len = pixel.y + TILE_SIZE;
	tmp_x = pixel.x;
	d = (pixel.x + TILE_SIZE) - pixel.x;
	steps = d;
	x_inc = d / steps;
	while (pixel.y < y_len)
	{
		pixel.x = tmp_x;
		while (pixel.x < (tmp_x + TILE_SIZE))
		{
			if (pixel.x < 1920 && pixel.x > 0)
				my_mlx_pixel_put(img, pixel.x, pixel.y, color);
			pixel.x += x_inc;
		}
		pixel.y += 1;
	}
}

static void	draw_player_pos(float y, float x, t_img *img, t_data data)
{
	float		y_len;
	float		tmp_x;

	(void) data;
	y += 5;
	x += 5;
	y_len = y + 10;
	tmp_x = x;
	while (y < y_len)
	{
		x = tmp_x;
		while (x < (tmp_x + 10))
		{
			my_mlx_pixel_put(img, x, y, 0xff3333);
			x += 1;
		}
		y += 1;
	}
}

static void	choose_color_of_tile( \
	t_env *env, t_vector_2d index, char **map, t_vector_2d count)
{
	if (index.y < 0 || index.x < 0 \
		|| index.y >= env->data.map_data.map_height \
		|| index.x >= env->data.map_data.map_width)
		draw_tile(count, 0x000000, &env->img);
	else if (map[index.y][index.x] && map[index.y][index.x] == '1')
		draw_tile(count, 0x828582, &env->img);
	else if (map[index.y][index.x] && map[index.y][index.x] == ' ')
		draw_tile(count, 0x000000, &env->img);
	else if (map[index.y][index.x] && (map[index.y][index.x] == 'D' \
		|| map[index.y][index.x] == 'I'))
		draw_tile(count, 0xe37f14, &env->img);
	else
		draw_tile(count, 0xdadbd9, &env->img);
}

void	draw_map(t_env *env)
{
	t_vector_2d	index;
	t_vector_2d	count;
	char		**map;

	map = env->data.map_data.map;
	count.y = 0;
	index.y = (int)env->data.p_pos_index.y - (MINI_MAP_SIZE / 2);
	while (count.y < MINI_MAP_SIZE)
	{
		count.x = 0;
		index.x = (int)env->data.p_pos_index.x - (MINI_MAP_SIZE / 2);
		while (count.x < MINI_MAP_SIZE)
		{
			choose_color_of_tile(env, index, map, count);
			index.x++;
			count.x++;
		}
		count.y++;
		index.y++;
	}
	draw_player_pos((MINI_MAP_SIZE / 2) * TILE_SIZE, \
		(MINI_MAP_SIZE / 2) * TILE_SIZE, &env->img, env->data);
}
