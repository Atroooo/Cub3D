/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:35:38 by gclement          #+#    #+#             */
/*   Updated: 2023/06/24 11:48:23 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	raycasting(t_env *env)
{
	float		angle;
	t_vector_2f	dir;
	float		x;
	t_ray		ray;
	int			i;

	angle = env->data.p_angle - 20.0 * RAD;
	x = 0;
	while (x < WIN_WIDTH)
	{
		dir.x = cos(angle);
		dir.y = sin(angle);
		dda(dir.x, dir.y, env, &ray);
		draw_wall(ray, env, x);
		i = search_opp(env->data.ray_opp.map.y, env->data.ray_opp.map.x, env->data);
		if (i != -1 && env->data.data_opp[i].x == -1)
			env->data.data_opp[i].x = x;
		angle += (RAD * (40.00 / (WIN_WIDTH)));
		env->data.angle = angle;
		x++;
	}
	env->data.ray_opp = ray;
}

// longueur mur = 20;
// largeur mur = 20;

//pix_x = 159.951569, pix_y = 19.927576, x = 7, y = 0
//pix_x = 140.002823, pix_y = 19.897259, x = 7, y = 0

// pix_x = 180.015488, pix_y = 99.999672, x = 9, y = 4
// pix_x = 180.002579, pix_y = 80.155655, x = 9, y = 4

// pix_x = 60.018707, pix_y = 59.967529, x = 3, y = 2
// pix_x = 79.997200, pix_y = 59.847008, x = 3, y = 2

// 19.978493

// 19.844017