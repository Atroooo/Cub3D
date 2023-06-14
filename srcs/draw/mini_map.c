/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:07:21 by gclement          #+#    #+#             */
/*   Updated: 2023/06/14 18:00:37 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_tile(float y, int x, uint32_t color, t_img *img)
{
	int		y_len;
	float	d;
	float	x_inc;
	float	steps;
	int		tmp_x;

	y *= TILE_SIZE;
	x *= TILE_SIZE;
	y_len = y + TILE_SIZE;
	tmp_x = x;
	d = (x + TILE_SIZE) - x;
	steps = d;
	x_inc = d / steps;
	while (y < y_len - 1)
	{
		x = tmp_x;
		while (x < (tmp_x + TILE_SIZE - 1))
		{
			if (x < 1920 && x > 0)
				my_mlx_pixel_put(img, x, y, color);
			x += x_inc;
		}
		y += 0.1;
	}
}

void	draw_player_pos(float y, int x, t_img *img)
{
	int		y_len;
	float	d;
	float	x_inc;
	float	steps;
	int		tmp_x;

	y_len = y + 10;
	tmp_x = x;
	d = (x + 10) - x;
	steps = d;
	x_inc = d / steps;
	while (y < y_len)
	{
		x = tmp_x;
		while (x < (tmp_x + 10))
		{
			if (x < 1920 && x > 0)
				my_mlx_pixel_put(img, x, y, 0xff3333);
			x += x_inc;
		}
		y += 0.1;
	}
}

void	draw_map(t_env *env)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	map = env->data.map_data.map;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == ' ')
				draw_tile((float)y, x, 0x000000, &env->img);
			if (map[y][x] == '1')
				draw_tile((float)y, x, 0x828582, &env->img);
			else if (map[y][x])
				draw_tile((float)y, x, 0xdadbd9, &env->img);
			x++;
		}
		y++;
	}
}
