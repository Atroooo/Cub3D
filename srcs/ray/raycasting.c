/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:35:38 by gclement          #+#    #+#             */
/*   Updated: 2023/06/28 00:21:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	set_x_for_opp(int x, t_env *env)
{
	int	i;

	i = search_opp(env->data.ray_opp.map.y, \
		env->data.ray_opp.map.x, env->data);
	if (i != -1 && env->data.ray_opp.active == TRUE
		&& env->data.data_opp[i].x == -1)
		env->data.data_opp[i].x = x;
}

void	raycasting(t_env *env)
{
	float		angle;
	t_vector_2f	dir;
	float		x;
	t_ray		ray;

	angle = env->data.p_angle - 20.0 * RAD;
	x = 0;
	env->data.ray_opp.active = FALSE;
	while (x < WIN_WIDTH)
	{
		dir.x = cos(angle);
		dir.y = sin(angle);
		dda(dir.x, dir.y, env, &ray);
		draw_wall(ray, env, x);
		set_x_for_opp(x, env);
		angle += (RAD * (40.00 / (WIN_WIDTH)));
		env->data.angle = angle;
		x++;
	}
	env->data.ray_opp = ray;
	mlx_put_image_to_window(env->windows.mlx, env->windows.win,
		env->img.img, 0, 0);
}
