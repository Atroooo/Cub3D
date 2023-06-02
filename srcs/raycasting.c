/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:35:38 by gclement          #+#    #+#             */
/*   Updated: 2023/06/02 16:01:59 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_line(t_env *env, int angle)
{
	int		y;
	int		x;
	float	pix_x;
	float	pix_y;

	y = env->data.p_pos_y / TILE_SIZE;
	x = env->data.p_pos_x / TILE_SIZE;
	pix_x = env->data.p_pos_x;
	pix_y = env->data.p_pos_y;
	while (env->data.map_data.map[y][x] != '1')
	{
		my_mlx_pixel_put(&env->img, pix_x, pix_y, 0x4a7337);
		pix_y -= 0.1;
		y = pix_y / TILE_SIZE;
		x = pix_x / TILE_SIZE;
	}
}
