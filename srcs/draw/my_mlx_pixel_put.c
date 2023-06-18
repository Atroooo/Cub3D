/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:13:27 by gclement          #+#    #+#             */
/*   Updated: 2023/06/18 17:50:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	if (x > 0 && x < 1920 && y > 0 && y < 1080)
	{
		dst = data->addr + (y * data->line_length + x * \
			(data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	my_mlx_put_line(t_img *img, int p1, int p2, uint32_t color)
{
	float	steps;
	float	d;
	float	x_inc;

	d = p2 - p1;
	steps = d;
	x_inc = d / steps;
	while (steps >= 0)
	{
		if (p1 < 1920 && p1 > 0)
			my_mlx_pixel_put(img, p1, p2, color);
		p1 += x_inc;
		steps--;
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
