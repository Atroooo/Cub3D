/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:17:15 by gclement          #+#    #+#             */
/*   Updated: 2023/06/05 17:40:43 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_wall(float distance, t_img *img, float *P_x)
{
	int		x;
	float	y;

	x = *P_x;
	y = 0;
	while (y < (WALL_H / distance) / 4)
	{
		my_mlx_pixel_put(img, x, y, 0x75cce6);
		y += 1;
	}
	while (y < (WALL_H / distance))
	{
		my_mlx_pixel_put(img, x, y, 0x757575);
		y += 1;
	}
	while (y < WIN_HEIGHT)
	{
		my_mlx_pixel_put(img, x, y, 0xe6bd75);
		y += 1;
	}
}
