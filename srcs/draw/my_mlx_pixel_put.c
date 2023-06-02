/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:13:27 by gclement          #+#    #+#             */
/*   Updated: 2023/06/02 11:11:18 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, uint32_t color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(uint32_t *)dst = color;
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
