/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:17:15 by gclement          #+#    #+#             */
/*   Updated: 2023/06/05 16:39:26 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_column(float distance, t_env *env, float *cam_x, float y)
{
	float	i;

	i = 0;
	//distance = env->data.r_perpendicular * cos(env->data.angle);
	while (i < 10)
	{
		i += 1;
		*cam_x += 1;
		draw_wall(distance, &env->img, cam_x, y);
	}
}

void	draw_wall(float distance, t_img *img, float *P_x, float y)
{
	int	x;
	int	i;

	x = *P_x;
	i = 0;
	if (distance < 0.20)
		distance = 0.20;
	while (i < WIN_HEIGHT / (WALL_H / distance) * 8)
	{
		my_mlx_pixel_put(img, x, y, 0x42d4f5);
		i++;
		y++;
	}
	i = 0;
	while (i < (WALL_H / distance))
	{
		my_mlx_pixel_put(img, x, y, 0x757575);
		i++;
		y++;
	}
	while (y < WIN_HEIGHT)
	{
		my_mlx_pixel_put(img, x, y, 0xf5b642);
		y++;
	}
}
