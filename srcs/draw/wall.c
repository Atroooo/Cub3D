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

void	draw_wall(float distance, t_img *img, float *P_x, float y)
{
	int	x;

	x = *P_x;
	while (y < (WALL_H / distance))
	{
		my_mlx_pixel_put(img, x, y, 0x757575);
		y += 0.1;
	}
}
