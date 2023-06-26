/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:35:38 by gclement          #+#    #+#             */
/*   Updated: 2023/06/26 14:34:58 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	raycasting(t_env *env)
{
	float		angle;
	t_vector_2f	dir;
	float		x;
	t_ray		ray;

	angle = env->data.p_angle - 20.0 * RAD;
	x = 0;
	while (x < WIN_WIDTH)
	{
		dir.x = cos(angle);
		dir.y = sin(angle);
		ray = dda(dir.x, dir.y, env);
		draw_wall(ray, env, x);
		angle += (RAD * (40.00 / (WIN_WIDTH)));
		env->data.angle = angle;
		x++;
	}
	mlx_put_image_to_window(env->windows.mlx, env->windows.win, \
		env->img.img, 0, 0);
}
