/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:07:21 by gclement          #+#    #+#             */
/*   Updated: 2023/06/19 15:47:55 by gclement         ###   ########.fr       */
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

void	draw_player_pos(float y, float x, t_vector_2f p_index, t_img *img)
{
	float		y_len;
	float		tmp_x;
	t_vector_2f	incr;

	(void) p_index;
	(void) incr;
	incr.y = ((p_index.y * TILE_SIZE) - (int)(p_index.y * TILE_SIZE));
	incr.x = ((p_index.x * TILE_SIZE) - (int)(p_index.x * TILE_SIZE));
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
			if (index.y < 0 || index.x < 0 || index.y >= env->data.map_data.map_height || index.x >= env->data.map_data.map_width)
				draw_tile(count, 0x000000, &env->img);
			else if (map[index.y][index.x] && map[index.y][index.x] == '1')
				draw_tile(count, 0x828582, &env->img);
			else if (map[index.y][index.x] && map[index.y][index.x] == ' ')
				draw_tile(count, 0x000000, &env->img);
			else
				draw_tile(count, 0xdadbd9, &env->img);

			index.x++;
			count.x++;
		}
		count.y++;
		index.y++;
	}
	draw_player_pos((MINI_MAP_SIZE / 2) * TILE_SIZE, (MINI_MAP_SIZE / 2) * TILE_SIZE, env->data.p_pos_index, &env->img);
}
